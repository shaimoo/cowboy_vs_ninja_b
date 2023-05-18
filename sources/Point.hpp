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
        void setx(double x);
        void sety(double y);

    public:
        // constructors
        Point(double x ,double y);


        double  distance(const Point &temp);
        void print();
        static Point moveTowards(const Point &source ,const Point &destination ,double dist);
        // get x,y
        double getx();
        double gety();
        bool operator==(const Point &temp)const;

    };

}

#endif
