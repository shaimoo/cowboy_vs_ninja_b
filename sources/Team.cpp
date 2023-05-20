#include "Team.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "iostream"
using namespace std;

namespace ariel{

    Team::Team(Character* lead):lead(lead)
    {
        if(lead->isinteam())
        {
            throw runtime_error("the player have team ");
        }
        lead->set_isinteam(true);
        team1.push_back(lead);

    }
    Team::~Team()
    {
        for(list<Character*>::iterator it=team1.begin();it != team1.end();it++)
        {
        delete *it;
        }
    }
    void Team::add(Character *temp)
    {
        if(temp->isinteam())
        {
            throw runtime_error("he have team all ready");
        }
        if(team1.size()==10)
        {
            throw runtime_error("cant add more to this team");
        }
        if(temp->get_type()=="cowboy")
        {
            team1.push_front(temp);
            temp->set_isinteam(true);
        }
        if(temp->get_type()=="ninja")
        {
            team1.push_back(temp);
            temp->set_isinteam(true);
        }

    }
    void Team::attack(Team *temp) {

        if(temp == nullptr)
        {
            throw invalid_argument("cant attack null pointer");
        }
        if(!leader_alive())
        {
            if(!replace_leader())
            {
                cout << "the team dead";
                return;
            }
        }
        if(!temp->stillAlive())
        {
            throw runtime_error("the enemy is dead");
        }

        Character *near = neartoLeader(temp);
        if (near == nullptr)
        {
            cout << "near is nullptr";
        }
        for (auto& member : team1)
        {
            if (!member->isAlive())
            {
                continue;
            }

            if (!near->isAlive())
            {
                near = neartoLeader(temp);
            }

            if (!near)
            {
                return;
            }

            member->attack(near);
        }


    }
    Team::Team(Team& other) : lead(other.lead), team1(other.team1){}

    Team::Team(Team&& other) noexcept: lead(std::move(other.lead)), team1(std::move(other.team1)){}

    bool Team::leader_alive()
    {
        return lead->isAlive();
    }

    SmartTeam::SmartTeam(Character *lead): Team(lead){}

    void SmartTeam::attack(Team* temp)
    {
        if (temp == nullptr)
        {
            throw invalid_argument("Can't attack null pointer");
        }

        if (!get_leader()->isAlive())
        {
            if (!replace_leader())
            {
                cout << "The team is dead";
                return;
            }
        }

        if (!temp->stillAlive())
        {
            throw runtime_error("The enemy is dead");
        }

        Cowboy* cowboy = dynamic_cast<Cowboy*>(get_leader());

        // Ninja attacks their closest character
        for (auto& member : get_team())
        {
            Ninja* ninja = dynamic_cast<Ninja*>(member);
            if (ninja != nullptr && ninja->isAlive())
            {

                Character* closestEnemy = neartoLeader(temp);
                if (closestEnemy != nullptr)
                {
                    ninja->attack(closestEnemy);
                }
            }
        }

        // Cowboy shoots the farthest character
        if (cowboy != nullptr && cowboy->isAlive())
        {
            Character* farthestEnemy = farthestFromLeader(temp);
            if (farthestEnemy != nullptr)
            {
                cowboy->shoot(farthestEnemy);
            }
        }
    }

Character* SmartTeam::farthestFromLeader(Team* temp)
{
    if (temp == nullptr || temp->get_team().empty())
    {
        return nullptr;
    }

    Character* farthestEnemy = nullptr;
    double maxDistance = 0.0;

    for (auto& enemy : temp->get_team())
    {
        if (enemy->isAlive())
        {
            double distance = get_leader()->distance(enemy);
            if (distance > maxDistance)
            {
                maxDistance = distance;
                farthestEnemy = enemy;
            }
        }
    }

    return farthestEnemy;
}

    Character* Team::get_leader()
    {
        return lead;
    }


    bool Team::replace_leader()
    {
        auto newLeaderIt = find_if(team1.begin(), team1.end(), [](const auto& member) {
            return member->isAlive();
        });

        if (newLeaderIt == team1.end())
        {
            return false;
        }

        int minDistance = lead->distance(*newLeaderIt);
        int newLeaderIndex = distance(team1.begin(), newLeaderIt);

        for (auto it = next(newLeaderIt); it != team1.end(); ++it)
        {
            if ((*it)->isAlive())
            {
                int distance = lead->distance(*it);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    newLeaderIndex = std::distance(team1.begin(), it);
                }
            }
        }

        auto it = team1.begin();
        std::advance(it, newLeaderIndex);
        lead = *it;
        return true;
    }


    int Team::stillAlive()
    {
        int counter=0;
        for(auto it=team1.begin();it != team1.end();it++)
        {
            if((*it)->isAlive())
            {
                counter++;
            }
        }
        return counter;
    }

    Character* Team::neartoLeader(Team* enemy)
    {
        Character* closest = nullptr;
        int minDistance = -1;

        for (const auto& enemyMember : enemy->team1)
        {
            if (!enemyMember->isAlive())
            {
                continue;
            }

            int distance = lead->distance(enemyMember);
            if (minDistance == -1 || distance < minDistance)
            {
                minDistance = distance;
                closest = enemyMember;
            }
        }

        return closest;
    }


    void Team::print()
    {
        for(auto it=team1.begin();it != team1.end();it++)
        {
            cout << (*it)->print() << endl;
        }

    }
    list<Character*>& Team::get_team()
    {
        return team1;
    }

}