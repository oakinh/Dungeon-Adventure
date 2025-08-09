#include <iostream>
#include "entity.h"

class Narrator {

    public:
        void welcomePlayer();
        void readDamage(const Entity& originator, const Entity& target, int damage);
};