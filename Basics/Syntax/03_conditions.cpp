/**
 * Tutorial 03: Conditions (If, Else)
 * 
 * Used to make decisions in code.
 * Structure:
 * if (condition) {
 *     // do something if true
 * } else {
 *     // do something else if false
 * }
 */

#include <iostream>

using namespace std;

int main() {
    int score;
    cout << "Enter your score (0-100): ";
    cin >> score;

    // 1. Basic If-Else
    if (score >= 50) {
        cout << "You Passed!\n";
    } else {
        cout << "You Failed. Try again!\n";
    }

    // 2. Else-If (Multiple conditions)
    if (score >= 90) {
        cout << "Grade: A\n";
    } else if (score >= 80) {
        cout << "Grade: B\n";
    } else if (score >= 70) {
        cout << "Grade: C\n";
    } else {
        cout << "Grade: D or F\n";
    }

    // 3. Switch Statement
    // Useful for checking a variable against specific values
    cout << "Enter a number (1-3): ";
    int num;
    cin >> num;

    switch(num) {
        case 1:
            cout << "One\n";
            break; // Break is important to stop falling through!
        case 2:
            cout << "Two\n";
            break;
        case 3:
            cout << "Three\n";
            break;
        default:
            cout << "Unknown number\n";
    }

    return 0;
}
