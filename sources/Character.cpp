#include "Character.hpp"
#include <string>
using namespace std;

namespace ariel{

    // constructors
    Character::Character(string name, int point_life, Point location):name(name),point_life(point_life), location(location) {}


    double Character::distance(const Character* temp) const
    {
        return location.distance(temp->getLocation());
    }

    bool Character::isAlive()const
    {
        if(point_life>0)
        {
            return true;
        }
        return false;
    }

    void Character::hit(int attack)
    {

        if(point_life<=0)
        {
            throw runtime_error("charter all ready dead");
        }
        if(attack<0)
        {
         throw invalid_argument("attack cant be negative");
        }
        point_life -= attack;
    }

    void Character::set_location(const Point &temp)
    {
        this->location = temp;
    }
    void  Character::set_type(std::string type_)
    {
        this->type = type_;
    }
    string Character::get_type() const
    {
        return this->type;
    }

    void Character::set_name(string name_)
    {
        this->name = name_;
    }

    void Character::set_point_life(int point_life_)
    {
        this->point_life = point_life_;
    }

    string Character::getName() const
    {
        return name;
    }
    bool Character::isinteam() const
    {
        return status;
    }
    void Character::set_isinteam(bool sign)
    {
        this->status = sign;
    }

    int Character::get_point_life()const
    {
        return point_life;
    }

    Point Character::getLocation() const
    {
        return location;
    }
    Character::~Character() {}

}
