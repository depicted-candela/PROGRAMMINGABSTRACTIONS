#include <iostream>
#include <vector>

using namespace std;

struct Point {
    double x;
    double y;
};

struct PolygonWithFiveVertices {
    Point point1;
    Point point2;
    Point point3;
    Point point4;
    Point point5;
    std::vector<Point> getVerticesInOrder() const {
        return {point1, point2, point3, point4, point5};
    }
};

string printsCentroidOfPolygonsWithFiveVertices(PolygonWithFiveVertices &polygon);

int main() {
    printsCentroidOfPolygonsWithFiveVertices();
    return 0;
}

string printsCentroidOfPolygonsWithFiveVertices(PolygonWithFiveVertices &polygon) {
    double cx, cy;
    cx = calculatesCentroidXOfPolygonsWithFiveVertices(polygon);
    cy = calculatesCentroidYOfPolygonsWithFiveVertices(polygon);
    cout << "The centroid of the polygon is (" + to_string(cx) + ", " + to_string(cy) + ")";
}

double calculatesCentroidXOfPolygonsWithFiveVertices(PolygonWithFiveVertices polygon) {
    double firstFactor, summation, x;
    firstFactor = (1.0 / (6.0 * calculatesAreaOfPolygon());
};

double summation(PolygonWithFiveVertices polygon, string axis) {
    std::vector<Point> vertices = polygon.getVerticesInOrder();
    int vertexCounter = 0;
    double factor1, factor2;
    double summation = 0;
    for (const auto& vertex : vertices) {
        if (vertexCounter != 4) break;
        summation +=  calculatesFactors(vertex, vertices.at(vertexCounter + 1), axis);
    }
}

double calculatesFactors(Point current, Point next, string axis) {
    double factor1, factor2;
    factor1 = axis == "x" ? current.x * next.x : current.y * next.y;
    factor2 = current.x * next.y - next.x * current.y;
    return factor1 * factor2;
}

double calculatesCentroidYOfPolygonsWithFiveVertices(PolygonWithFiveVertices polygon) {

};

double 