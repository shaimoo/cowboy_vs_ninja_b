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
         Ninja(string name,int point_of_life, Point location , int speed): Character(name,point_of_life,location),speed(speed){}

         virtual void move(Character* enemy);
         virtual void slash(Character* enemy);
         string print() override;
         int get_speed();
    };
    class YoungNinja:public Ninja
    {
    public:
        YoungNinja(string name, Point location);
    };

    class TrainedNinja:public Ninja
    {
    public:
        TrainedNinja(string name, Point location);
    };

    class OldNinja:public Ninja
    {
    public:
        OldNinja(string name, Point location);
    };

}
#endif
