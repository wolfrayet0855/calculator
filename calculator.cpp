#include <iostream>
#include <iomanip> // For fixed and setprecision
using namespace std;

double calculate(double num1, double num2, char op) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': 
            if (num2 == 0) {
                cout << "Error: Division by zero!" << endl;
                return NAN; // Return "Not a Number"
            }
            return num1 / num2;
        default:
            cout << "Error: Invalid operator!" << endl;
            return NAN;
    }
}

int main() {
    double num1, num2, result;
    char op, choice;

    do {
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter operator (+, -, *, /): ";
        cin >> op;

        cout << "Enter second number: ";
        cin >> num2;

        result = calculate(num1, num2, op);

        if (!isnan(result)) { // Check if result is valid
            cout << fixed << setprecision(2); // Set precision to 2 decimal places
            cout << "Result: " << result << endl;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Goodbye!" << endl;
    return 0;
}
