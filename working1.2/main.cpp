#include <iostream>
#include <fstream>
#include <string>

// Function to display the contents of a file
void displayFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }
    std::string line;
    std::cout << "Contents of " << filename << ":\n";
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    std::cout << std::endl;
    file.close();
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file" << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        // Check if the line is not empty (contains non-whitespace characters)
        if (!line.empty() && line.find_first_not_of(' ') != std::string::npos) {
            outputFile << line << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();

    // Display the contents of the files
    displayFile("input.txt");
    displayFile("output.txt");

    return 0;
}
