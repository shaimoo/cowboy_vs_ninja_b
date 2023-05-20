#ifndef COWBOY
#define COWBOY
#include "Character.hpp"

namespace ariel{
    class Cowboy : public Character
    {
    private:
        int bullets;

    public:
        Cowboy(string name,Point loctation);
        void reload();
        void shoot(Character *target);
        string print() const override;
        void attack(Character *enemy) override;
        bool hasboolets();
    };
}
#endif
