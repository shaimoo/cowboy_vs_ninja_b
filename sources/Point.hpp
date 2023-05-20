#ifndef POINT
#define POINT
#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel{

    class Point{
    private:
        double x,y;
        // set x,y
        void setx(double xpoint);
        void sety(double ypoint);

    public:
        // constructors
        Point(double xpoint ,double ypoint);


        double  distance(const Point &temp) const;
        void print();
        static Point moveTowards(const Point &source ,const Point &destination ,double dist);
        // get x,y
        double getx();
        double gety();
        string tostring() const;
        bool operator==(const Point &temp)const;

    };

}

#endif
