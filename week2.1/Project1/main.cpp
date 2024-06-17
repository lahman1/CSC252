#include <iostream>
#include <cmath>

#if __cplusplus >= 202002L
#include <numbers> // For std::numbers::pi in C++20 or later
#else
// Define pi manually if std::numbers::pi or M_PI is not available
const double PI = 3.14159265358979323846;
#endif

using namespace std;

class SodaCan {
private:
    double radius;
    double height;

public:
    // Constructor to initialize radius and height
    SodaCan(double r, double h) : radius(r), height(h) {}

    // Accessor to compute volume
    double volume() const {
#if __cplusplus >= 202002L
        return std::numbers::pi * radius * radius * height; // C++20 or later
#else
        return PI * radius * radius * height; // Pre C++20
#endif
    }

    // Accessor to compute surface area
    double surface_area() const {
#if __cplusplus >= 202002L
        return 2 * std::numbers::pi * radius * height + 2 * std::numbers::pi * radius * radius; // C++20 or later
#else
        return 2 * PI * radius * height + 2 * PI * radius * radius; // Pre C++20
#endif
    }
};

int main() {
    double radius, height;
    cout << "Enter the radius of the soda can: ";
    cin >> radius;
    cout << "Enter the height of the soda can: ";
    cin >> height;

    SodaCan can(radius, height);

    cout << "Volume of the soda can: " << can.volume() << " cubic units" << endl;
    cout << "Surface area of the soda can: " << can.surface_area() << " square units" << endl;

    return 0;
}
