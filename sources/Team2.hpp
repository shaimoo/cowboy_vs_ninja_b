#ifndef TEAM2
#define TEAM2
#include <vector>
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"

using  namespace std;
namespace ariel{
    class Team2
    {
    private:
        vector<Ninja*> Ninjas;
        vector<Cowboy*> Cowboys;
        Character *lead;

    public:
        explicit Team2(Character *lead);
        void add(Character *temp );
        void attack(Team2 *temp );
        int stillAlive();
        void print();
    };


}


#endif
