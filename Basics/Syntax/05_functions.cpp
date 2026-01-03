/**
 * Tutorial 05: Functions
 * 
 * Functions allow you to reuse code.
 * Structure:
 * returnType functionName(parameters) {
 *     // body
 *     return something;
 * }
 */

#include <iostream>
#include <string>

using namespace std;

// 1. Void Function (Returns nothing)
void greet(string name) {
    cout << "Hello, " << name << "!\n";
}

// 2. Function returning a value
int add(int a, int b) {
    return a + b;
}

// 3. Function Forward Declaration
// If you define function below main, you must declare it above main.
bool isEven(int n);

int main() {
    greet("Student"); // Calls void function

    int sum = add(5, 10); // Calls int function
    cout << "5 + 10 = " << sum << "\n";

    if (isEven(4)) {
        cout << "4 is Even\n";
    }

    return 0;
}

// Definition of isEven
bool isEven(int n) {
    return (n % 2 == 0);
}
