#include <cmath>
#include <stdexcept>
#include "Point.hpp"
using namespace std;
namespace ariel{

    Point::Point(double xpoint, double ypoint):x(xpoint),y(ypoint){}

    double Point::distance(const Point &temp) const{
        double distx = pow(x-temp.x,2);
        double disty = pow(y-temp.y,2);
        return sqrt(distx+disty);
    }
    string Point::tostring() const
    {
    return    "(" + to_string(x) + "," + to_string(y) + ")";
    }
    double Point::getx() {
        return x;
    }

    double Point::gety() {
        return y;
    }

    void Point::setx(double xpoint) {
        this->x=xpoint;
    }

    void Point::sety(double ypoint) {
        this->y=ypoint;
    }

    void Point::print() {
        cout << "(" << x << "," << y << ")";
    }

    Point Point::moveTowards(const Point &source, const Point &destination, double dist) {
        double distance = destination.distance(source);

        if (distance < dist || dist<0 )
        {
        throw invalid_argument("the distance is too far cant be reached");
        }
        double ratio = dist/distance;
        double pointx = source.x + ratio*(destination.x - source.x);
        double pointy = source.y + ratio*(destination.y - source.y);

      return Point(pointx,pointy);
    }

    bool Point::operator==(const Point &temp) const {
        return temp.x == x && temp.y==y;
    }

}
