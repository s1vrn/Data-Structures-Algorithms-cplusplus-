/**
 * Tutorial 09: String Operations
 * 
 * C++ strings (std::string) have many built-in functions to manipulate text.
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    string text = "Competitive Programming is awesome!";

    // 1. Length / Size
    cout << "Length: " << text.length() << " characters\n";

    // 2. Accessing characters
    cout << "First char: " << text[0] << "\n";
    cout << "Last char: " << text[text.length() - 1] << "\n";

    // 3. Finding a substring
    // Returns the starting index, or string::npos if not found
    size_t found = text.find("awesome");
    if (found != string::npos) {
        cout << "'awesome' found at index: " << found << "\n";
    }

    // 4. Extracting a Substring
    // substr(start_index, length)
    string sub = text.substr(12, 11); // "Programming"
    cout << "Extracted: " << sub << "\n";

    // 5. Appending / Concatenation
    string hello = "Hello";
    hello += " Readers"; // Same as hello = hello + " Readers"
    cout << "Appended: " << hello << "\n";

    // 6. Clearing and Checking if empty
    string temp = "data";
    temp.clear();
    if (temp.empty()) {
        cout << "String is now empty.\n";
    }

    return 0;
}
