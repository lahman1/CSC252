#include "common.h"
#include <fstream>
#include <cstdlib>

void createBinaryFile(const std::string& name, int length) {
    int* arr = new int[length];
    for (int i = 0; i < length; ++i) {
        arr[i] = std::rand() % 1000;
    }
    writeBinary(arr, length, name);
    delete[] arr;
}

void writeBinary(int* values, int length, const std::string& name) {
    std::ofstream outFile(name, std::ios::binary);
    outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outFile.write(reinterpret_cast<const char*>(values), length * sizeof(int));
    outFile.close();
}

int* readBinary(int& length, const std::string& name) {
    std::ifstream inFile(name, std::ios::binary);
    inFile.read(reinterpret_cast<char*>(&length), sizeof(length));
    int* arr = new int[length];
    inFile.read(reinterpret_cast<char*>(arr), length * sizeof(int));
    inFile.close();
    return arr;
}

void selection_sort(int* values, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (values[j] < values[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(values[i], values[minIndex]);
    }
}

bool binary_search_recursive(int* values, int key, int start, int end) {
    if (start > end) {
        return false;
    }
    int mid = start + (end - start) / 2;
    if (values[mid] == key) {
        return true;
    }
    else if (values[mid] > key) {
        return binary_search_recursive(values, key, start, mid - 1);
    }
    else {
        return binary_search_recursive(values, key, mid + 1, end);
    }
}

bool binary_search(int* values, int size, int key) {
    return binary_search_recursive(values, key, 0, size - 1);
}
