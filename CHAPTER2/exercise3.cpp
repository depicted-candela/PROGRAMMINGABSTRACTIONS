#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

struct Line {
    double a;
    double b;
    double c;
};

bool areTheLinesParallel(Line l1, Line l2);
string printsTheIntersectionOfTwoRectLines(Line l1, Line l2);
double findsTheXIntersection(Line l1, Line l2);
double findsTheYIntersection(Line l1, Line l2, double x);

int main () {
    // Example 2: Intersected lines
    Line line1 = {1, 2, 3};
    Line line2 = {4, 2, 3};
    if (areTheLinesParallel(line1, line2)) {
        cout << "The lines are parallel" << endl;
        return 0;
    }
    cout << printsTheIntersectionOfTwoRectLines(line1, line2) << endl;
    // Example 2: Parallel lines
    Line line3 = {2, 4, 6};
    Line line4 = {2, 4, 10};
    if (areTheLinesParallel(line3, line4)) {
        cout << "The lines are parallel" << endl;
    } else {
        cout << printsTheIntersectionOfTwoRectLines(line3, line4) << endl;
    }
    return 0;
}

bool areTheLinesParallel(Line line1, Line line2) {
    return line1.a == line2.a;
};

string printsTheIntersectionOfTwoRectLines(Line line1, Line line2) {
    double x, y;
    x = findsTheXIntersection(line1, line2);
    y = findsTheYIntersection(line1, line2, x);
    return "The intersection between the lines is: (" + to_string(x) + ", " + to_string(y) +  ")";
}

double findsTheXIntersection(Line l1, Line l2) {
    double factor1, factor2;
    factor1 = ((l1.c / l1.b) - (l2.c / l1.b));
    factor2 = ((l1.b * l2.b) * ((l1.a * l2.b) * (l2.a * l1.b)));
    return factor1 * factor2;
}

double findsTheYIntersection(Line l1, Line l2, double x) {
    double y_l1, y_l2;
    y_l1 = (l1.c / l1.b) - l1.a * x;
    y_l2 = (l2.c / l2.b) - l2.a * x;
    if (y_l1 == y_l2) return y_l1;
    throw std::runtime_error("The lines do not intersect at the given x-coordinate.");
}