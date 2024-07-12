#ifndef COMMON_H
#define COMMON_H

#include <string>

void createBinaryFile(const std::string& name, int length);
void writeBinary(int* values, int length, const std::string& name);
int* readBinary(int& length, const std::string& name);
void selection_sort(int* values, int size);
bool binary_search(int* values, int size, int key);

#endif
