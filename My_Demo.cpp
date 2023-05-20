#include <iostream>
#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"

using namespace ariel;
using namespace std;

int main() {
    // Create characters
    Cowboy cowboy("John", Point(0, 0));
    TrainedNinja ninja("Ryu", Point(2, 2));
    OldNinja oldNinja("Master Splinter", Point(3, 3));
    YoungNinja youngNinja("Leonardo", Point(1, 1));

    // Print character information
    cout << "Cowboy: " << cowboy.getName() << ", Location: " << cowboy.getLocation() << endl;
    cout << "Trained Ninja: " << ninja.getName() << ", Location: " << ninja.getLocation() << endl;
    cout << "Old Ninja: " << oldNinja.getName() << ", Location: " << oldNinja.getLocation() << endl;
    cout << "Young Ninja: " << youngNinja.getName() << ", Location: " << youngNinja.getLocation() << endl;

    // Perform actions
    cowboy.reload();
    cowboy.shoot(&ninja);
    cowboy.shoot(&oldNinja);
    cowboy.shoot(&youngNinja);
    cowboy.shoot(&youngNinja);
    cowboy.shoot(&youngNinja);

    // Check if characters are alive
    cout << "Is Cowboy alive? " << (cowboy.isAlive() ? "Yes" : "No") << endl;
    cout << "Is Trained Ninja alive? " << (ninja.isAlive() ? "Yes" : "No") << endl;
    cout << "Is Old Ninja alive? " << (oldNinja.isAlive() ? "Yes" : "No") << endl;
    cout << "Is Young Ninja alive? " << (youngNinja.isAlive() ? "Yes" : "No") << endl;

    // Create teams and simulate battle
    Team team1(&cowboy);
    Team2 team2(&ninja);
    team1.add(&oldNinja);
    team1.add(&youngNinja);

    team1.attack(&team2);

    // Check if teams are still alive
    cout << "Is Team 1 still alive? " << (team1.stillAlive() ? "Yes" : "No") << endl;
    cout << "Is Team 2 still alive? " << (team2.stillAlive() ? "Yes" : "No") << endl;


    // Create a Cowboy character
    Cowboy cowboy("Cowboy", 10, 100);
    Team team(cowboy);

    // Create Ninja characters
    Ninja youngNinja("Young Ninja", 14, 100);
    Ninja trainedNinja("Trained Ninja", 12, 120);
    Ninja oldNinja("Old Ninja", 8, 150);

    team.add(&youngNinja);
    team.add(&trainedNinja);
    team.add(&oldNinja);

    // Create an enemy team

    Ninja enemyNinja1("Enemy Ninja 1", 10, 80);
    // Create Ninja characters for the enemy team
    Team enemyTeam(enemyNinja1);
    Ninja enemyNinja2("Enemy Ninja 2", 9, 90);


    enemyTeam.add(&enemyNinja2);

    try {
        // Attack the enemy team
        team.attack(&enemyTeam);
    } catch (const std::exception& e) {
        std::cout << "An error occurred: " << e.what() << std::endl;
    }

    // Create Team2 object
    Team2 team2;

    // Add characters to Team2
    Character character1("Character 1", 10, 100);
    Character character2("Character 2", 12, 120);
    team2.add(&character1);
    team2.add(&character2);

    // Call the specialTeam2Function
    team2.specialTeam2Function();


    Character character3("Character 3", 8, 150);
    SmartTeam smartTeam(character3);

    Character character4("Character 4", 9, 130);
    smartTeam.add(&character4);

    // Call the smartFunction
    smartTeam.smartFunction();

    return 0;
}
