#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Microwave {
private:
    int cookTime;    // Time in seconds
    int powerLevel;  // 1 for 100%, 2 for 50%

public:
    // Constructor that calls the reset function
    Microwave() {
        reset();
    }

    // Function to increase time by 30 seconds
    void addTime() {
        cookTime += 30;
    }

    // Function to switch between power levels
    void switchPowerLevel() {
        if (powerLevel == 1) {
            powerLevel = 2;
        }
        else {
            powerLevel = 1;
        }
    }

    // Function to reset the microwave
    void reset() {
        cookTime = 0;
        powerLevel = 1;
    }

    // Function to start the microwave
    void start() const {
        if (cookTime == 0) {
            cout << "Nothing to cook! Please add time." << endl;
            return;
        }

        cout << "Starting cooking..." << endl;
        cout << "Cooking for " << cookTime << " seconds at level "
            << powerLevel << " (" << (powerLevel == 1 ? "100%" : "50%") << ")" << endl;

        // Simulate the cooking time, using a shorter sleep time to simulate cooking faster
        int sleepDuration = cookTime / 10; // Simulate 10 times faster
        this_thread::sleep_for(chrono::seconds(sleepDuration));

        cout << "Cooking complete!" << endl;
    }

    // Function to display the current state
    void display() const {
        cout << "Current cook time: " << cookTime << " seconds" << endl;
        cout << "Current power level: " << powerLevel << " (" << (powerLevel == 1 ? "100%" : "50%") << ")" << endl;
    }
};

// Function to show the menu to user
void showMenu() {
    cout << "\nMicrowave Menu:\n";
    cout << "1. Add 30 seconds\n";
    cout << "2. Switch power level\n";
    cout << "3. Start\n";
    cout << "4. Reset\n";
    cout << "5. Show current state\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Microwave myMicrowave;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            myMicrowave.addTime();
            cout << "Added 30 seconds." << endl;
            break;
        case 2:
            myMicrowave.switchPowerLevel();
            cout << "Switched power level." << endl;
            break;
        case 3:
            myMicrowave.start();
            break;
        case 4:
            myMicrowave.reset();
            cout << "Microwave reset." << endl;
            break;
        case 5:
            myMicrowave.display();
            break;
        case 6:
            cout << "Exiting." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
