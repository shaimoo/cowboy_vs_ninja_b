#ifndef TEAM
#define TEAM
#include <vector>
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"

using  namespace std;
namespace ariel{
    class Team
    {
    private:
        vector<Ninja*> Ninjas;
        vector<Cowboy*> Cowboys;
        Character *lead;

    public:
        explicit Team(Character *lead);
        void add(Character *temp );
        void attack(Team *temp );
        int stillAlive();
        void print();
    };


}


#endif
