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
            bool status = false;
            string type;



        public:
            Character() = delete;

            Character(const Character&) = delete;  // Delete copy constructor
            Character& operator=(const Character&) = delete;  // Delete copy assignment operator
            Character(Character&&) = delete;
            Character& operator=(Character&&) = delete;
        // set func
            Character(string name ,int point_life ,Point location);
            virtual ~Character();
            void set_location(const Point &temp);
            void set_name(string name);
            void set_point_life(int point_life);
            void set_type(string type_);
            virtual bool isAlive()const ;
            virtual  void hit(int attack) ;
            virtual double distance(const Character* temp) const;
            virtual string print() const =0 ;
            virtual void attack(Character* temp) = 0 ;

            //get func
            string get_type() const;
            int get_point_life()const;
            string getName() const;
            Point getLocation() const;
            bool isinteam() const;
            void set_isinteam(bool sign);


    };


}

#endif
