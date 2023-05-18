#include "Ninja.hpp"

using namespace std;

namespace ariel{


    YoungNinja::YoungNinja(string name, Point location) : Ninja(name, 100, location, 14) {}
    TrainedNinja::TrainedNinja(string name, Point location): Ninja(name,120,location,12) {}
    OldNinja::OldNinja(string name, Point location) : Ninja(name,150,location,8) {}

    void Ninja::slash(Character* enemy) {}
    void Ninja::move(Character* enemy) {}
    int  Ninja::get_speed()
    {
        return speed;
    }
    string Ninja::print() {
        return "";
    }


}
