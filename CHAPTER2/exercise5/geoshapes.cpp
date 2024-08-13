#include <iostream>
#include <cmath>
#include <cassert>
#include "geoshapes.h"

using namespace std;

double calculateDistance(GeoPoint a, GeoPoint b) {
    return std::sqrt((a.longitude - b.latitude) * (a.longitude - b.latitude) + (a.longitude - b.longitude) * (a.longitude - b.longitude));
}

double calculateArea(ShapeType shape) {
    double area;
    switch (shape) {
        case 0:
            return calculateCircleArea();
            break;
        case 1:
            cout << "Lines does not have defined area" << endl;
            return 0;
        case 2:
            cout << "Lines does not have defined area" << endl;
            return 0;
        default:
            cout << "The shape is not known";
            return 0;
    }
}

double calculateCircleArea() {
    double radius;
    cout << "Enter the radius of the circle" << endl;
    cout << "radius: ";
    cin >> radius;
    return radius * radius * PI;
}

void testCalculateDistance() {
    GeoPoint p1 = {0.0, 0.0};
    GeoPoint p2 = {3.0, 4.0};
    assert(calculateDistance(p1, p2) == 5.0);
    cout << "calculateDistance test passed." << endl;
}

void testCalculateArea() {
    cin.clear();
    cout << "Give a 5 get a successful assert" << endl;
    double area = calculateArea(CIRCLE);
    assert(area == 25.0 * PI);
    assert(calculateArea(LINE) == 0.0);
    assert(calculateArea(POINT) == 0.0);
    cout << "calculateArea test passed." << endl;
}

int main() {
    testCalculateDistance();
    testCalculateArea();
    return 0;
}