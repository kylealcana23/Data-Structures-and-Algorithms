#include <iostream>
using namespace std;

int main() {
    int choice;
    float temp, converted_temp;


    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Fahrenheit to Celsius\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter temperature in Celsius: ";
        cin >> temp;
        converted_temp = (temp * 9.0/5.0) + 32;
        cout << "Temperature in Fahrenheit: " << converted_temp << " F\n";
    } else if (choice == 2) {
        cout << "Enter temperature in Fahrenheit: ";
        cin >> temp;
        converted_temp = (temp - 32) * 5.0/9.0;
        cout << "Temperature in Celsius: " << converted_temp << " C\n";
    } else {
        cout << "PLEASE CHOOSE ONLY 1 OR 2\n";
    }

    return 0;
}
