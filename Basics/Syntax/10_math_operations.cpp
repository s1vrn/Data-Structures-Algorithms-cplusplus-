/**
 * Tutorial 10: Math Operations
 * 
 * C++ provides the `<cmath>` library for advanced mathematical functions.
 */

#include <iostream>
#include <cmath> // Required for math functions
#include <algorithm> // For min, max

using namespace std;

int main() {
    double x = 9.0;
    double y = 2.0;

    // 1. Power and Square Root
    cout << "9 to the power of 2: " << pow(x, y) << "\n";
    cout << "Square root of 9: " << sqrt(x) << "\n";

    // 2. Rounding
    double num = 3.7;
    cout << "Floor of 3.7: " << floor(num) << " (Round down)\n";
    cout << "Ceil of 3.7: " << ceil(num) << " (Round up)\n";
    cout << "Round 3.7: " << round(num) << " (Nearest integer)\n";

    // 3. Absolute Value
    int neg = -15;
    cout << "Absolute value of -15: " << abs(neg) << "\n";

    // 4. Min / Max
    // Note: min and max are in <algorithm>
    cout << "Min of 10 and 20: " << min(10, 20) << "\n";
    cout << "Max of 10 and 20: " << max(10, 20) << "\n";

    // 5. Trigonometry (Input is in Radians)
    double pi = acos(-1.0); // Precise PI
    cout << "Sin(PI/2): " << sin(pi/2) << "\n";

    return 0;
}
