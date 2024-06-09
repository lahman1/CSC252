#include <iostream>
#include <cstring> // Required for string manipulation functions

// Function prototypes
int length(const char* str);
int indexof(const char* str, char ch);
char* replace(char* str, char oldChar, char newChar);
char* concat(const char* str1, const char* str2);

int main() {
    // Test length function
    const char* testStr1 = "Hello, World!";
    std::cout << "Length of \"" << testStr1 << "\": " << length(testStr1) << std::endl;

    // Test indexof function
    char searchChar = 'W';
    std::cout << "Index of '" << searchChar << "' in \"" << testStr1 << "\": " << indexof(testStr1, searchChar) << std::endl;

    // Test replace function
    char mutableStr[] = "banana";
    char oldChar = 'a';
    char newChar = 'o';
    std::cout << "Original string: " << mutableStr << std::endl;
    std::cout << "After replacing '" << oldChar << "' with '" << newChar << "': " << replace(mutableStr, oldChar, newChar) << std::endl;

    // Test concat function
    const char* testStr2 = " Goodbye!";
    char* concatenated = concat(testStr1, testStr2);
    std::cout << "Concatenated string: " << concatenated << std::endl;

    // Clean up dynamically allocated memory
    delete[] concatenated;

    return 0;
}

// Implementations
int length(const char* str) {
    int count = 0;
    while (*str != '\0') {
        ++count;
        ++str;
    }
    return count;
}

int indexof(const char* str, char ch) {
    const char* original = str;
    while (*str != '\0') {
        if (*str == ch) {
            return str - original; // Return the index
        }
        ++str;
    }
    return -1; // Character not found
}

char* replace(char* str, char oldChar, char newChar) {
    char* original = str;
    while (*str != '\0') {
        if (*str == oldChar) {
            *str = newChar; // Replace character
        }
        ++str;
    }
    return original;
}

char* concat(const char* str1, const char* str2) {
    int len1 = length(str1);
    int len2 = length(str2);

    char* result = new char[len1 + len2 + 1]; // +1 for null terminator
    char* temp = result;

    while (*str1 != '\0') {
        *temp = *str1;
        ++temp;
        ++str1;
    }

    while (*str2 != '\0') {
        *temp = *str2;
        ++temp;
        ++str2;
    }

    *temp = '\0'; // Null terminator
    return result;
}
