#include "Team2.hpp"

#include "iostream"
using namespace std;

namespace ariel{

    Team2::Team2(Character* lead):lead(lead)
    {
        this->add(lead);
    }
    void Team2::add(Character *temp){

    }
    void Team2::attack(Team2 *temp) {
        return;
    }
    int Team2::stillAlive() {
        return 0;
    }
    void Team2::print() {
        return;
    }
}