#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <limits>

// Date class implementation
class Date {
public:
    int year, month, day;

    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    bool operator==(const Date& other) const {
        return year == other.year && month == other.month && day == other.day;
    }
};

// Appointment class (abstract)
class Appointment {
protected:
    std::string description;
    Date date;

public:
    Appointment(const std::string& desc, const Date& d) : description(desc), date(d) {}

    virtual bool occurs_on(int year, int month, int day) const = 0;
    virtual void print() const {
        std::cout << description << " on " << date.year << "-" << (date.month < 10 ? "0" : "") << date.month
            << "-" << (date.day < 10 ? "0" : "") << date.day << std::endl;
    }

    virtual ~Appointment() = default;
};

// Day appointment class
class Day : public Appointment {
public:
    Day(const std::string& desc, const Date& d) : Appointment(desc, d) {}

    bool occurs_on(int year, int month, int day) const override {
        return date.year == year && date.month == month && date.day == day;
    }
};

// Monthly appointment class
class Monthly : public Appointment {
public:
    Monthly(const std::string& desc, const Date& d) : Appointment(desc, d) {}

    bool occurs_on(int year, int month, int day) const override {
        return date.day == day && date.year == year;
    }
};

// Function to add appointments
void add_appointment(std::vector<std::unique_ptr<Appointment>>& appointments) {
    std::string description;
    int year, month, day;
    int choice;

    std::cout << "Enter the description of the appointment: ";
    std::cin.ignore();
    std::getline(std::cin, description);

    std::cout << "Enter the year (e.g., 2024): ";
    std::cin >> year;
    std::cout << "Enter the month (1-12): ";
    std::cin >> month;
    std::cout << "Enter the day (1-31): ";
    std::cin >> day;

    std::cout << "Is this a (1) One-time or (2) Monthly recurring appointment? Enter 1 or 2: ";
    std::cin >> choice;

    if (choice == 1) {
        appointments.push_back(std::make_unique<Day>(description, Date(year, month, day)));
    }
    else if (choice == 2) {
        appointments.push_back(std::make_unique<Monthly>(description, Date(year, 0, day)));
    }
    else {
        std::cout << "Invalid choice. Appointment not added.\n";
    }
}

// Function to print appointments for a given date
void print_appointments_on_date(const std::vector<std::unique_ptr<Appointment>>& appointments, int year, int month, int day) {
    bool found = false;
    std::cout << "\nAppointments on " << year << "-" << (month < 10 ? "0" : "") << month << "-" << (day < 10 ? "0" : "") << day << ":\n";
    for (const auto& appt : appointments) {
        if (appt->occurs_on(year, month, day)) {
            appt->print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No appointments found on this date.\n";
    }
}

// Function to print all current appointments
void print_all_appointments(const std::vector<std::unique_ptr<Appointment>>& appointments) {
    std::cout << "\nAll Current Appointments:\n";
    for (const auto& appt : appointments) {
        appt->print();
    }
    if (appointments.empty()) {
        std::cout << "No appointments available.\n";
    }
}

int main() {
    std::vector<std::unique_ptr<Appointment>> appointments;

    // Sample appointments
    appointments.push_back(std::make_unique<Day>("Dentist appointment", Date(2024, 6, 24)));
    appointments.push_back(std::make_unique<Monthly>("Pay bills", Date(2024, 0, 1)));
    appointments.push_back(std::make_unique<Day>("Team meeting", Date(2024, 6, 27)));
    appointments.push_back(std::make_unique<Monthly>("Monthly review", Date(2024, 0, 1)));

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add an appointment\n";
        std::cout << "2. Check appointments for a date\n";
        std::cout << "3. View all current appointments\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            add_appointment(appointments);
        }
        else if (choice == 2) {
            int year, month, day;
            std::cout << "Enter the date to check (year month day): ";
            std::cin >> year >> month >> day;
            print_appointments_on_date(appointments, year, month, day);
        }
        else if (choice == 3) {
            print_all_appointments(appointments);
        }
        else if (choice == 4) {
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }

        // Clear any remaining input to prevent errors
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
