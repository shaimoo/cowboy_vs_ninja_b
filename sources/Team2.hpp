#ifndef TEAM2
#define TEAM2
#include <vector>
#include "Character.hpp"
#include "Ninja.hpp"
#include "Team.hpp"

using  namespace std;
namespace ariel
{
    class Team2 : public Team
    {
    public:
         Team2(Character *lead);
        void add(Character *temp ) override;
        ~Team2();
    };

}


#endif
