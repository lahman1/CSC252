#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include "module3.h"
#include "common.h"

const int SIZE = 1000;  // Define SIZE here

class BinaryReader {
private:
    int* values;
    int size;

    void readValues(const std::string& name) {
        std::ifstream inFile(name, std::ios::binary);
        inFile.read(reinterpret_cast<char*>(&size), sizeof(size));
        values = new int[size];
        inFile.read(reinterpret_cast<char*>(values), size * sizeof(int));
        inFile.close();
    }

public:
    BinaryReader(const std::string& name) {
        readValues(name);
    }

    ~BinaryReader() {
        delete[] values;
    }

    int* getValues() {
        return values;
    }

    int getSize() {
        return size;
    }
};

class Analyzer {
protected:
    int* values;
    int size;

    void cloneValues(int* values, int size) {
        this->size = size;
        this->values = new int[size];
        std::copy(values, values + size, this->values);
    }

public:
    Analyzer(int* values, int size) {
        cloneValues(values, size);
    }

    virtual ~Analyzer() {
        delete[] values;
    }

    virtual std::string analyze() = 0;
};

class StatisticsAnalyzer : public Analyzer {
public:
    StatisticsAnalyzer(int* values, int size) : Analyzer(values, size) {
        selection_sort(this->values, this->size);
    }

    std::string analyze() override {
        int min = values[0];
        int max = values[size - 1];
        double mean = 0;
        for (int i = 0; i < size; ++i) {
            mean += values[i];
        }
        mean /= size;

        double median;
        if (size % 2 == 0) {
            median = (values[size / 2 - 1] + values[size / 2]) / 2.0;
        }
        else {
            median = values[size / 2];
        }

        int mode = values[0];
        int modeCount = 1;
        int currentCount = 1;
        for (int i = 1; i < size; ++i) {
            if (values[i] == values[i - 1]) {
                currentCount++;
            }
            else {
                currentCount = 1;
            }
            if (currentCount > modeCount) {
                modeCount = currentCount;
                mode = values[i];
            }
        }

        std::string result = "The minimum value is " + std::to_string(min) + "\n";
        result += "The maximum value is " + std::to_string(max) + "\n";
        result += "The mean value is " + std::to_string(mean) + "\n";
        result += "The median value is " + std::to_string(median) + "\n";
        result += "The mode value is " + std::to_string(mode) + " which occurred " + std::to_string(modeCount) + " times\n";
        return result;
    }
};

class DuplicateAnalyzer : public Analyzer {
public:
    DuplicateAnalyzer(int* values, int size) : Analyzer(values, size) {}

    std::string analyze() override {
        std::unordered_map<int, int> valueCount;
        for (int i = 0; i < size; ++i) {
            valueCount[values[i]]++;
        }

        int duplicateCount = 0;
        for (const auto& pair : valueCount) {
            if (pair.second > 1) {
                duplicateCount++;
            }
        }

        return "There were " + std::to_string(duplicateCount) + " duplicated values\n";
    }
};

class MissingAnalyzer : public Analyzer {
public:
    MissingAnalyzer(int* values, int size) : Analyzer(values, size) {}

    std::string analyze() override {
        std::unordered_set<int> valueSet(values, values + size);
        int missingCount = 0;

        for (int i = 0; i < 1000; ++i) {
            if (valueSet.find(i) == valueSet.end()) {
                missingCount++;
            }
        }

        return "There were " + std::to_string(missingCount) + " missing values\n";
    }
};

void runModule3() {
    createBinaryFile("binary.dat", SIZE);
    BinaryReader br("binary.dat");

    StatisticsAnalyzer sa(br.getValues(), br.getSize());
    std::cout << sa.analyze() << '\n';
    DuplicateAnalyzer da(br.getValues(), br.getSize());
    std::cout << da.analyze() << '\n';
    MissingAnalyzer ma(br.getValues(), br.getSize());
    std::cout << ma.analyze() << '\n';
}
