#include <iostream>
#include "module1.h"
#include "module2.h"
#include "module3.h"
#include "module4.h"

int main() {
    std::srand(std::time(0));

    while (true) {
        std::cout << "Choose a module to run:\n";
        std::cout << "1. Module 1: Binary File Operations (Create, Write, and Read)\n";
        std::cout << "2. Module 2: Binary File Reader and Basic Analysis\n";
        std::cout << "3. Module 3: Advanced Analysis (Statistics, Duplicates, Missing Values)\n";
        std::cout << "4. Module 4: Sorting and Searching with Analysis\n";
        std::cout << "5. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "\nRunning Module 1...\n\n";
            runModule1();
            break;
        case 2:
            std::cout << "\nRunning Module 2...\n\n";
            runModule2();
            break;
        case 3:
            std::cout << "\nRunning Module 3...\n\n";
            runModule3();
            break;
        case 4:
            std::cout << "\nRunning Module 4...\n\n";
            runModule4();
            break;
        case 5:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid choice, please try again.\n";
        }
        std::cout << "\n";
    }
    return 0;
}
