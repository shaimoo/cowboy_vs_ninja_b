#include "Ninja.hpp"

using namespace std;

namespace ariel{



    void Ninja::slash(Character* enemy)
    {
        if(!enemy->isAlive())
        {
            throw runtime_error("cant slash dead charter");
        }
        if(enemy == this)
        {
            throw runtime_error("cant slash himself");
        }
        if(!isAlive())
        {
            throw runtime_error("cant slash the ninja is dead");
        }
        if(getLocation().distance(enemy->getLocation()) > 1)
        {
            return;
        }
        enemy->hit(40);

    }
    void Ninja::move(Character* enemy)
    {
        if(!isAlive())
        {
            throw runtime_error("the ninja is dead");
        }
        double  distance_to_enemy = getLocation().distance(enemy->getLocation());
        double distance_ = 0;
        if (speed < distance_to_enemy)
        {
            distance_ = speed;
        }
        else
        {
            distance_ = distance_to_enemy;
        }
        set_location(Point::moveTowards(getLocation(),enemy->getLocation(),distance_));
    }
    int  Ninja::get_speed()
    {
        return speed;
    }

    void Ninja::attack(Character *enemy)
    {
        if (getLocation().distance(enemy->getLocation()) > 1)
        {
            move(enemy);
            return;
        }
        slash(enemy);
    }
    string Ninja::print()const
    {
        if(!isAlive())
        {
            return "name : (N) (" + getName() + ") location: "+ getLocation().tostring();
        }
        return "name : (N) " + getName() + " life point :" + to_string(get_point_life()) + " location: " + getLocation().tostring();
    }


}
