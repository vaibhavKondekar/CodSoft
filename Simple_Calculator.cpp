#include <iostream>
using namespace std;
int main() {
    double n1, n2, rslt;
    char operation;
    cout << "Enter first number: ";
    cin >> n1;
    cout << "Enter second number: ";
    cin >> n2;
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;
    switch (operation) {
        case '+':
            rslt = n1 + n2;
            break;
        case '-':
            rslt = n1 - n2;
            break;
        case '*':
            rslt = n1 * n2;
            break;
        case '/':
            if (n2 != 0) {
                rslt = n1 / n2;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
                return 1; 
            }
            break;
        default:
            cout << "Invalid operation. Please choose +, -, *, or /." << endl;
            return 1; 
    }
    cout << "Result: " << rslt << endl;
    return 0; 
}
