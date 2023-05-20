#ifndef YOUNGNINJA
#define YOUNGNINJA
#include "Ninja.hpp"
#include "Character.hpp"

constexpr int HPYOUNG = 100;
constexpr int SPEEDYOUNG = 14;

using namespace std;

namespace ariel{
    class YoungNinja:public Ninja
    {
    public:
        YoungNinja(string name, Point location): Ninja(std::move(name),HPYOUNG,location,SPEEDYOUNG) {}

        ~YoungNinja() override;
    };

}
#endif
