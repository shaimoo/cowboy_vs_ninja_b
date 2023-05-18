#include "Cowboy.hpp"
#include "iostream"

namespace ariel{
    Cowboy::Cowboy(std::string name, ariel::Point loctation) : Character(name,110,loctation),bullets(6){}

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
    string Cowboy::print() {
        return "Cowboy name:";
    }
    void Cowboy::reload() {}
    void Cowboy::shoot(ariel::Character *target) {}
}