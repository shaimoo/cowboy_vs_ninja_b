#define TEST
#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
using namespace ariel;

    TEST_SUITE("Point"){
        TEST_CASE("Point constructor")
        {
            Point temp(73.5, 563.4);
            CHECK_EQ(temp.getx() , 73.5);
            CHECK_EQ(temp.gety() , 563.4);
        }

        TEST_CASE("distance func")
        {
            ariel::Point point1(1, 1);
            ariel::Point point2(2, 2);
            CHECK_EQ(point1.distance(point2) , 1);
            CHECK_EQ(point2.distance(point1) , 1);
            CHECK_EQ(point1.distance(point1) , 0);
        }

        TEST_CASE("moveTowards func")
        {
            ariel::Point point1(1, 1);
            ariel::Point point2(2, 2);
            Point point3 = point1.moveTowards(point1,point2,2);
            CHECK_EQ(point3.getx() ,1);
            CHECK_EQ(point3.gety(),1);
        }
        TEST_CASE("print func")
        {
            ariel::Point point1(1, 1);
            CHECK_NOTHROW(point1.print());
        }
    }

    TEST_SUITE("Cowboy")
    {
        ariel::Point point1(1, 1);
        ariel::Point point2(2, 2);
        ariel::Cowboy temp = Cowboy("shay",point1);
        ariel::Cowboy temp2 = Cowboy("moshe",point2);
        TEST_CASE("gets func")
        {
            CHECK_NOTHROW(temp.hasboolets());
            CHECK_EQ(temp.get_location(),point1);
            CHECK_EQ(temp.get_point_life(),100);
            CHECK_EQ(temp.get_name(),"shay");
        }

        TEST_CASE("print func")
        {
            CHECK_NOTHROW(temp.print());
        }
        TEST_CASE("reload func")
        {
            int i=0;
            while(i < 6){
                temp.shoot(&temp2);
            i++;
            }
            CHECK_NOTHROW(temp.reload());
        }
        TEST_CASE("shoot func")
        {
            CHECK_NOTHROW(temp.shoot(&temp2));
        }

    }
    TEST_SUITE("Ninja old trained and young")
    {
            ariel::Point point1(1, 1);
            ariel::Point point2(2, 2);
            ariel::Point point3(3, 3);
            ariel::Point point4(4, 4);
            ariel::Point point7(7, 7);
            ariel::Ninja temp = Ninja("shay",100,point1,5);
            ariel::Ninja temp2 = Ninja("moshe",100,point2,7);
            ariel::YoungNinja  temp_young =  YoungNinja("shay",point3);
            ariel::OldNinja  temp_old =  OldNinja("noam",point3);
            ariel::TrainedNinja  temp_trained =  TrainedNinja("shalom",point3);
        TEST_CASE("Ninja print func")
        {
            CHECK_NOTHROW(temp.print());
            CHECK_NOTHROW(temp_young.print());
            CHECK_NOTHROW(temp_old.print());
            CHECK_NOTHROW(temp_trained.print());
        }
        TEST_CASE("Ninja move func")
        {
           temp.move(&temp2);
            temp_trained.move(&temp_old);
            CHECK_EQ(temp.get_location(),temp2.get_location());
            CHECK_EQ(temp_trained.get_location(),temp_old.get_location());
        }
        TEST_CASE("Ninja slash func")
        {
            int health = temp2.get_point_life();
            temp.slash(&temp2);
            CHECK_LE(temp2.get_point_life(),health);
        }
        TEST_CASE("Ninja gets func")
        {
            CHECK_EQ(temp.get_speed(),5);
            CHECK_EQ(temp2.get_speed(),7);
            CHECK_EQ(temp_young.get_speed(),14);
            CHECK_EQ(temp_old.get_speed(),12);
            CHECK_EQ(temp_trained.get_speed(),8);
        }

    }

    TEST_SUITE("Team")
    {
        ariel::Point point1(1, 1);
        ariel::Point point2(2, 2);
        ariel::Point point3(3, 3);
        ariel::Point point4(4, 4);
        ariel::Point point7(7, 7);
        ariel::Cowboy temp = Cowboy("shay",point1);
        ariel::Cowboy temp2 = Cowboy("moshe",point2);
        ariel::YoungNinja  temp_young =  YoungNinja("shay",point3);
        ariel::OldNinja  temp_old =  OldNinja("noam",point3);
        ariel::TrainedNinja  temp_trained =  TrainedNinja("shalom",point3);
        TEST_CASE("Team add func")
        {
            Team ninjas = Team(&temp);
            CHECK_NOTHROW(ninjas.add(&temp2));

            CHECK_NOTHROW(ninjas.add(&temp_young));
            CHECK_NOTHROW(ninjas.add(&temp_old));
        }
        TEST_CASE("Team print func")
        {
            Team ninjas = Team(&temp);
            ninjas.add(&temp2);
            ninjas.add(&temp_young);
            ninjas.add(&temp_old);
            CHECK_NOTHROW(ninjas.print());
        }
        TEST_CASE("Team attack func")
        {
            Team ninjas = Team(&temp_young);
            ninjas.add(&temp_old);
            ninjas.add(&temp_trained);
            Team cowboys = Team(&temp);
            cowboys.add(&temp2);
            CHECK_NOTHROW(ninjas.attack(&cowboys));
        }
        TEST_CASE("Team still_Alive func")
        {
            Team ninjas = Team(&temp_young);
            ninjas.add(&temp_trained);
            ninjas.add(&temp_old);
            Team cowboys = Team(&temp);
            cowboys.add(&temp2);
            CHECK_NOTHROW(ninjas.attack(&cowboys));
            CHECK(ninjas.stillAlive());
        }

    }
    TEST_SUITE("Team2")
    {
        ariel::Point point1(1, 1);
        ariel::Point point2(2, 2);
        ariel::Point point3(3, 3);
        ariel::Point point4(4, 4);
        ariel::Point point7(7, 7);
        ariel::Cowboy temp = Cowboy("shay",point1);
        ariel::Cowboy temp2 = Cowboy("moshe",point2);
        ariel::YoungNinja  temp_young =  YoungNinja("shay",point3);
        ariel::OldNinja  temp_old =  OldNinja("noam",point3);
        ariel::TrainedNinja  temp_trained =  TrainedNinja("shalom",point3);

        TEST_CASE("Team2 add func")
        {
            Team2 ninjas = Team2(&temp);
            CHECK_NOTHROW(ninjas.add(&temp2));
            CHECK_NOTHROW(ninjas.add(&temp_young));
            CHECK_NOTHROW(ninjas.add(&temp_old));
        }
        TEST_CASE("Team2 print func")
        {
            Team2 ninjas = Team2(&temp);
            ninjas.add(&temp2);
            ninjas.add(&temp_old);
            ninjas.add(&temp_young);
            CHECK_NOTHROW(ninjas.print());
        }
        TEST_CASE("Team2 attack func")
        {
            Team2 ninjas = Team2(&temp_old);
            ninjas.add(&temp_young);
            ninjas.add(&temp_trained);
            Team2 cowboys = Team2(&temp);
            cowboys.add(&temp2);
            CHECK_NOTHROW(ninjas.attack(&cowboys));
        }
        TEST_CASE("Team2 still_Alive func")
        {
            Team2 ninjas = Team2(&temp_old);
            ninjas.add(&temp_young);
            ninjas.add(&temp_trained);
            Team2 cowboys = Team2(&temp);
            cowboys.add(&temp2);
            CHECK_NOTHROW(ninjas.attack(&cowboys));
            CHECK(ninjas.stillAlive());
        }

    }