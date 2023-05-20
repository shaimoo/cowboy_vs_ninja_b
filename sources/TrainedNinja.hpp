#ifndef TRAIN_NINJA
#define TRAIN_NINJA
#include "Ninja.hpp"
#include "Character.hpp"

constexpr int HPTRAIN = 120;
constexpr int SPEEDTRAIN = 12;

using namespace std;

namespace ariel{
    class TrainedNinja:public Ninja
    {
    public:
        TrainedNinja(string name, Point location): Ninja(std::move(name),HPTRAIN,location,SPEEDTRAIN) {}

        ~TrainedNinja() override;
    };

}
#endif
