#include "combat_orchestration.h"
#include "entity.h"

void takeEnemyTurn(Entity& enemy, Entity& player) {
    enemy.m_combatSystem.attack(player.m_combatSystem);
}

void takePlayerTurn(Entity& player) {
}

void runTurns(std::vector<Entity>& entities, Entity& player) {
    int aliveCount = 1; // Player is assumed alive
    bool isFirstPass = true;
    do {
        for (auto& entity : entities) {
            if (entity.getType() == 0) {
                // Player turn


                continue;
            }
            bool isAlive = entity.getIsAlive();
            if (isAlive) {
                if (isFirstPass) ++aliveCount;
                takeEnemyTurn(entity, player);

            } else {
                if (!isFirstPass) --aliveCount;
            }
        }
    } while (aliveCount > 1);
    // Call narrator.roomCompleted ?
}