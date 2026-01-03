/**
 * Tutorial 11: Type Casting
 * 
 * Type casting is converting a variable from one data type to another.
 * This is crucial when performing math between different types (like int and double).
 */

#include <iostream>
#include <iomanip> // For formatting output

using namespace std;

int main() {
    // 1. Implicit Casting (Automatic)
    // C++ automatically converts int to double
    int a = 10;
    double b = a; 
    cout << "Implicit cast: " << b << "\n";

    // 2. Explicit Casting (Manual)
    // Let's divide two integers
    int sum = 15;
    int count = 4;
    
    // Incorrect: Integer division truncates decimals
    double avg_wrong = sum / count; // 15 / 4 = 3
    cout << "Wrong Average: " << avg_wrong << "\n";

    // Correct using static_cast<Type>(variable)
    double avg_correct = static_cast<double>(sum) / count; // 3.75
    cout << "Correct Average (static_cast): " << avg_correct << "\n";

    // 3. Char to Int (ASCII Values)
    char ch = 'A';
    int ascii = static_cast<int>(ch);
    cout << "ASCII value of 'A': " << ascii << "\n";

    // 4. Int to Char
    int val = 66;
    char letter = static_cast<char>(val);
    cout << "Character for ASCII 66: " << letter << "\n";

    return 0;
}
