#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Ninja.hpp"
#include "Point.hpp"

constexpr int HPOLD = 150;
constexpr int SPEEDOLD = 8;

namespace ariel {
    class OldNinja : public Ninja
    {
    public:
        OldNinja(string name, Point location) : Ninja(std::move(name),HPOLD,location,SPEEDOLD) {};

        ~OldNinja() override;
    };
}
#endif
