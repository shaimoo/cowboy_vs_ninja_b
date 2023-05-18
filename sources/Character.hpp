#ifndef CHARACTER
#define CHARACTER
#include "Point.hpp"
#include <string>

using namespace std;
namespace ariel{
    class Character{
        private:
            Point location;
            int point_life;
            string name;

            // set func
            void set_location(const Point &temp);
            void set_name(string name);
            void set_point_life(int point_life);

        public:
            Character(string name ,int point_life ,Point location);

            virtual bool isAlive() ;
            virtual  void hit(int attack) ;
            virtual double distance(const Character &temp) ;
            virtual string print()=0;

            //get func
            int get_point_life();
            string get_name();
            Point get_location();
            virtual ~Character()=default;

    };


}

#endif
