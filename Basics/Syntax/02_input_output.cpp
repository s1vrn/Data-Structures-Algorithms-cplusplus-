/**
 * Tutorial 02: Input and Output
 * 
 * - cout (Console Output): Used to print to the screen.
 * - cin (Console Input): Used to get data from the user/keyboard.
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    int number;
    
    // Output
    cout << "Enter a lucky number: ";
    
    // Input
    // The program will pause here and wait for you to type and press Enter.
    cin >> number;
    
    cout << "You entered: " << number << "\n";

    // Multiple inputs
    int a, b;
    cout << "Enter two numbers separated by space: ";
    cin >> a >> b;
    
    cout << "Sum: " << a + b << "\n";

    return 0;
}
