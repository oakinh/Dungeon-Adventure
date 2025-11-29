#pragma once

#include "combat_orchestration.h"
#include "entity.h"
#include "dungeon.h"
#include "narrator.h"

class Narrator {
private:
    static size_t getValidSelection(const std::pair<size_t, size_t>& inclusiveBounds);

    public:
        static void welcomePlayer();
        static void readDamage(const Entity& originator, const Entity& target, int damage);
        static void readRoom(const Room* room);
        static const CombatOrchestration::PlayerDecisionsInfo& runPlayerTurn(Entity& player);
        static size_t askForPotionSelection(const Entity& player);
        static int takeIntSelection();
        static void readStatusEffectApplied(StatusEffect& statusEffect, Entity& entity);
        static Entity& askForTarget(std::vector<Entity>& enemies);
};