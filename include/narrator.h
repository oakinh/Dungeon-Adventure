#pragma once

#include "entity.h"
#include "dungeon.h"
#include "narrator.h"

class Narrator {

    public:
        static void welcomePlayer();
        static void readDamage(const Entity& originator, const Entity& target, int damage);
        static void readRoom(const Room* room);
        static void runPlayerTurn(Entity& player);
        static size_t askForPotionSelection(const Entity& player);
        static int takeIntSelection();
        static void readStatusEffectApplied(StatusEffect& statusEffect, Entity& entity);
};