#include <iostream>
#include <string>

// Function to swap characters at position i and j
void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

// Recursive function to generate permutations
void permute(std::string str, int left, int right) {
    // Base case: if left index is equal to right index, print the permutation
    if (left == right) {
        std::cout << str << std::endl;
    }
    else {
        // Iterate from left to right
        for (int i = left; i <= right; i++) {
            // Swap the current index with the left
            swap(str[left], str[i]);
            // Recur for the rest of the string
            permute(str, left + 1, right);
            // Backtrack and undo the swap
            swap(str[left], str[i]);
        }
    }
}

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::cin >> str;
    int n = str.size();
    std::cout << "Permutations of the string are:\n";
    permute(str, 0, n - 1);
    return 0;
}
