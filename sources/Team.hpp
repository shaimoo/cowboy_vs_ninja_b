#ifndef TEAM
#define TEAM
#include <list>
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

using  namespace std;
namespace ariel{
    class Team
    {
    private:
        list<Character*> team1;
        Character *lead;

    public:
        Team(Character *lead);
        Team(Team &temp);
        virtual ~Team();

        Team& operator=(const Team& other) = default;
        Team& operator=(Team&& other) noexcept = default;


        Team(Team &&other)noexcept;
        Character* neartoLeader(Team* enemy);
        bool leader_alive();
        bool replace_leader();
        virtual  void add(Character *temp );
        virtual  void attack(Team *temp );
        Character* get_leader();
        int stillAlive();
        void print();
        list<Character*>& get_team();
    };

    class SmartTeam: public Team
    {
        public:
            SmartTeam(Character *lead);
            void attack(Team *Team);
            Character* farthestFromLeader(Team* temp);

    };


}


#endif
