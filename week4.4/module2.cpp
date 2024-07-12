#include <iostream>
#include <fstream>
#include "module2.h"
#include "common.h"

const int SIZE = 1000;

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
    StatisticsAnalyzer(int* values, int size) : Analyzer(values, size) {}

    std::string analyze() override {
        int min = values[0];
        int max = values[0];
        double mean = 0;
        for (int i = 0; i < size; ++i) {
            if (values[i] < min) min = values[i];
            if (values[i] > max) max = values[i];
            mean += values[i];
        }
        mean /= size;
        return "Min: " + std::to_string(min) + ", Max: " + std::to_string(max) + ", Mean: " + std::to_string(mean);
    }
};

void runModule2() {
    createBinaryFile("binary.dat", SIZE);
    BinaryReader br("binary.dat");

    StatisticsAnalyzer sa(br.getValues(), br.getSize());
    std::cout << sa.analyze() << std::endl;
}
