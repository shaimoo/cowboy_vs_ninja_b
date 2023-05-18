#include <cmath>
#include <stdxcept>
#include "Point.hpp"
using namespace std;
namespace ariel{

    Point::Point(double x, double y):x(x),y(y){}

    double Point::distance(const ariel::Point &temp) {
        double distx = pow(x-temp.x,2);
        double disty = pow(y-temp.y,2);
        return sqrt(distx+disty);
    }

    double Point::getx() {
        return x;
    }

    double Point::gety() {
        return y;
    }

    void Point::setx(double x) {
        this->x=x;
    }

    void Point::sety(double y) {
        this->y=y;
    }

    void Point::print() {
        cout << "(" << x << "," << y << ")";
    }

    Point Point::moveTowards(const ariel::Point &source, const ariel::Point &destination, double dist) {
        double distance = dist.distance(source);

        if (distance < dist)
        {
        throw invalid_argument("the distance is too far cant be reached");
        }
        double ratio = dist/distance;
        double pointx = source.x + ratio(destination.x - source.x);
        double pointy = source.y + ratio(destination.y - source.y);

      return Point(pointx,pointy);
    }

    bool Point::operator==(const ariel::Point &temp) const {
        return temp.x == x && temp.y==y;
    }

}
