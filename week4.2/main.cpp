#include <iostream>
#include <string>

// Function to recursively find the binary equivalent
void decimalToBinary(int n, std::string& binaryStr) {
    // Base case: when n becomes 0
    if (n == 0) {
        return;
    }

	// Recursive case: if n is even, append 0 to the binary string
    if (n % 2 == 0) {
        binaryStr += '0';
    }
    else {
        binaryStr += '1';
    }

    decimalToBinary(n / 2, binaryStr);
}

int main() {
    int decimalNumber;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimalNumber;

    if (decimalNumber == 0) {
        std::cout << "Binary equivalent: 0" << std::endl;
        return 0;
    }

    std::string binaryStr;
    decimalToBinary(decimalNumber, binaryStr);

    // Reverse the captured binary digits to get the correct binary representation
    std::reverse(binaryStr.begin(), binaryStr.end());

    std::cout << "Binary equivalent: " << binaryStr << std::endl;
    return 0;
}
