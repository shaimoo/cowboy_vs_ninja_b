#include "Character.hpp"
#include <string>
using namespace std;

namespace ariel{

    // constructors
    Character::Character(string name, int point_life, Point location):name(name),point_life(point_life), location(location) {}


    double Character::distance(const Character &temp){return 0;}

    bool Character::isAlive() {
        return false;
    }

    void Character::hit(int attack) {}

    void Character::set_location(const Point &temp)
    {
        this->location = temp;
    }

    void Character::set_name(string name_)
    {
        this->name = name_;
    }

    void Character::set_point_life(int point_life_)
    {
        this->point_life = point_life_;
    }

    string Character::get_name()
    {
        return name;
    }

    int Character::get_point_life()
    {
        return point_life;
    }

    Point Character::get_location()
    {
        return location;
    }

}
