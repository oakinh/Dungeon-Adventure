#pragma once

#include "entity.h"
#include "dungeon.h"

class Narrator {

    public:
        void welcomePlayer();
        void readDamage(const Entity& originator, const Entity& target, int damage);
        void readRoom(const Room* room);
};