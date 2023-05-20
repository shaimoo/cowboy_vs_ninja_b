#include "Cowboy.hpp"
#include "iostream"

namespace ariel{
    Cowboy::Cowboy(std::string name, ariel::Point loctation) : Character(name,110,loctation),bullets(6)
    {
        this->set_type("cowboy");
    }

    bool Cowboy::hasboolets()
    {
        if(bullets > 0 )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string Cowboy::print() const
    {
        if(!isAlive())
        {
            return "name : (C) ("+ getName() + ")" + + " location " + getLocation().tostring();
        }
        return "name : (C) "+ getName() + " helth " + to_string(get_point_life()) + " location " + getLocation().tostring();
    }
    void Cowboy::reload()
    {
        if (!isAlive())
        {
            throw runtime_error("cant reload the cowboy is dead");
        }
        bullets = 6;
    }

    void Cowboy::attack(Character *enemy)
    {
        shoot(enemy);
    }

    void Cowboy::shoot(ariel::Character *target)
    {
        if(this == target)
        {
            throw runtime_error("cant suicide");
        }
        if(!hasboolets())
        {
            reload();
            return;
        }
        if(!isAlive())
        {
        throw runtime_error("you are dead");
        }
        if(!target->isAlive())
        {
            throw runtime_error("the target all  ready dead");
        }
        target->hit(10);
        this->bullets--;
    }
}
