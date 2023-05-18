#include "Team.hpp"

#include "iostream"
using namespace std;

namespace ariel{

    Team::Team(Character* lead):lead(lead)
    {
        this->add(lead);
    }
    void Team::add(Character *temp){

    }
    void Team::attack(Team *temp) {
        return;
    }
    int Team::stillAlive() {
        return 0;
    }
    void Team::print() {
        return;
    }
}