#ifndef NINJA
#define NINJA

#include "Character.hpp"
using namespace std;

namespace ariel{
    class Ninja:public Character
    {
    private:
        int speed;

    public:
         Ninja(string name,int point_of_life, Point location , int speed): Character(std::move(name),point_of_life,location),speed(speed)
         {
             this->set_type("ninja");
         }
         void attack(Character* enemy) override;
         virtual void move(Character* enemy);
         virtual void slash(Character* enemy);
         string print() const override;
         int get_speed();
    };

}
#endif
