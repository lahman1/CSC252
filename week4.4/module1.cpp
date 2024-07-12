#include <iostream>
#include <cstdlib>
#include "module1.h"
#include "common.h"

const int SIZE = 1000;

int* createArray(int length) {
    int* arr = new int[length];
    for (int i = 0; i < length; ++i) {
        arr[i] = std::rand() % 1000;
    }
    return arr;
}

void runModule1() {
    int* arr = createArray(SIZE);
    writeBinary(arr, SIZE, "binary.dat");

    delete[] arr;
    arr = nullptr;

    int length;
    arr = readBinary(length, "binary.dat");

    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
}
