#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>
#include <sstream>

// Base class Person
class Person {
protected:
    std::string name;
    std::string phone_number;
    std::string email;

public:
    Person(const std::string& name, const std::string& phone_number, const std::string& email)
        : name(name), phone_number(phone_number), email(email) {}

    virtual std::string to_string() const {
        return "Person named " + name + " has phone number " + phone_number + " and can be reached at " + email;
    }

    virtual ~Person() = default;
};

// Student class inheriting from Person
class Student : public Person {
private:
    std::string year;

public:
    Student(const std::string& name, const std::string& phone_number, const std::string& email, const std::string& year)
        : Person(name, phone_number, email), year(year) {}

    std::string to_string() const override {
        return Person::to_string() + ", and is in the " + year + " year";
    }
};

// Employee class inheriting from Person
class Employee : public Person {
protected:
    double salary;

public:
    Employee(const std::string& name, const std::string& phone_number, const std::string& email, double salary)
        : Person(name, phone_number, email), salary(salary) {}

    std::string to_string() const override {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << salary;
        return Person::to_string() + ", and earns $" + oss.str() + " annually";
    }
};

// Faculty class inheriting from Employee
class Faculty : public Employee {
private:
    std::string title;

public:
    Faculty(const std::string& name, const std::string& phone_number, const std::string& email, double salary, const std::string& title)
        : Employee(name, phone_number, email, salary), title(title) {}

    std::string to_string() const override {
        return Employee::to_string() + ", and is a/an " + title;
    }
};

// Staff class inheriting from Employee
class Staff : public Employee {
private:
    std::string role;

public:
    Staff(const std::string& name, const std::string& phone_number, const std::string& email, double salary, const std::string& role)
        : Employee(name, phone_number, email, salary), role(role) {}

    std::string to_string() const override {
        return Employee::to_string() + ", and handles " + role;
    }
};

// Main function
int main() {
    std::vector<std::unique_ptr<Person>> people;

    // Adding instances of Person, Student, Employee, Faculty, and Staff
    people.push_back(std::make_unique<Person>("Susan", "800-555-1212", "susan@quirkymail.com"));
    people.push_back(std::make_unique<Student>("Jerry", "123-456-7890", "jerjer@nat.edu", "sophomore"));
    people.push_back(std::make_unique<Employee>("Larry", "333-444-5555", "larry@threestooges.org", 123456.00));
    people.push_back(std::make_unique<Faculty>("Linda", "987-654-3210", "lindalou@whoknew.edu", 150000.00, "adjunct professor"));
    people.push_back(std::make_unique<Staff>("Jane", "567-123-6565", "jane@whizkid.com", 100000.00, "registration"));

    // Iterating over the vector and printing each person's information
    for (const auto& person : people) {
        std::cout << person->to_string() << std::endl;
    }

    return 0;
}
