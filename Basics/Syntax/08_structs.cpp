/**
 * Tutorial 08: Structs (Structures)
 * 
 * A struct is a way to group multiple variables (of different types) into one "object".
 * This is useful for representing concepts like a Point, a Student, or an Item.
 */

#include <iostream>
#include <string>

using namespace std;

// Defining a Struct
struct Student {
    string name;
    int age;
    double gpa;

    // A function inside a struct is called a "Method"
    void display() {
        cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << "\n";
    }
};

struct Point {
    int x, y;
};

int main() {
    // 1. Using Student struct
    Student s1;
    s1.name = "Alice";
    s1.age = 20;
    s1.gpa = 3.8;

    cout << "Student 1 Info: ";
    s1.display();

    // 2. Initializing during declaration
    Student s2 = {"Bob", 22, 3.5};
    cout << "Student 2 Info: ";
    s2.display();

    // 3. Array of Structs
    Point path[3] = {{0,0}, {1,2}, {3,4}};
    
    cout << "Points in path:\n";
    for(int i=0; i<3; i++) {
        cout << "(" << path[i].x << ", " << path[i].y << ")\n";
    }

    return 0;
}
