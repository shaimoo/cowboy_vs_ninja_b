#include "Team2.hpp"
#include "iostream"
using namespace std;

namespace ariel{

    Team2::Team2(Character *lead): Team(lead){}
    Team2::~Team2(){}
    void Team2::add(Character *temp){

        if(temp->isinteam())
        {
            throw runtime_error("he have team all ready");
        }
        if(get_team().size()==10)
        {
            throw runtime_error("cant add more player");
        }
        get_team().push_back(temp);
        temp->set_isinteam(true);
    }


}