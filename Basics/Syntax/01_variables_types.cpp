/**
 * Tutorial 01: Variables and Data Types
 * 
 * In C++, we store data in "variables". Each variable has a "type".
 * Common Types:
 * - int: Integers (whole numbers), e.g., 5, -10
 * - double: Decimal numbers, e.g., 3.14, -0.01
 * - char: Single character, e.g., 'A', '$'
 * - string: Text, e.g., "Hello World"
 * - bool: True/False logic, e.g., true, false
 */

#include <iostream>
#include <string> // Required for string

using namespace std;

int main() {
    // 1. Integer
    int age = 21;
    cout << "My age is: " << age << "\n";

    // 2. Double (Floating point)
    double pi = 3.14159;
    cout << "Value of PI: " << pi << "\n";

    // 3. Character
    // Note: Must use single quotes ' '
    char grade = 'A';
    cout << "Grade: " << grade << "\n";

    // 4. String
    // Note: Must use double quotes " "
    string message = "Welcome to C++!";
    cout << "Message: " << message << "\n";

    // 5. Boolean
    // Prints 1 for true, 0 for false
    bool isCodingFun = true;
    bool isHard = false;
    cout << "Is coding fun? " << isCodingFun << "\n";
    cout << "Is it too hard? " << isHard << "\n";

    return 0;
}
