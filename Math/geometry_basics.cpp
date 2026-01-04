/**
 * 📐 Geometry Basics
 * 
 * Introduction to points, lines, and the cross product.
 * Cross product is the most important tool in CP geometry!
 */

#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
    
    // Vector arithmetic
    Point operator-(const Point& other) const {
        return {x - other.x, y - other.y};
    }
};

// Cross Product of vectors OA and OB
// res > 0: Counter-clockwise (Left turn)
// res < 0: Clockwise (Right turn)
// res = 0: Collinear
long long crossProduct(Point a, Point b, Point c) {
    Point ab = b - a;
    Point ac = c - a;
    return ab.x * ac.y - ab.y * ac.x;
}

// Distance between two points
double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    Point a = {0, 0};
    Point b = {4, 0};
    Point c = {4, 4};
    Point d = {4, -4};

    cout << "Turn A -> B -> C: ";
    long long cp1 = crossProduct(a, b, c);
    if (cp1 > 0) cout << "Left Turn (CCW)\n";
    else if (cp1 < 0) cout << "Right Turn (CW)\n";
    else cout << "Collinear\n";

    cout << "Turn A -> B -> d: ";
    long long cp2 = crossProduct(a, b, d);
    if (cp2 > 0) cout << "Left Turn (CCW)\n";
    else if (cp2 < 0) cout << "Right Turn (CW)\n";
    else cout << "Collinear\n";

    cout << "Distance A-C: " << dist(a, c) << endl;

    return 0;
}
