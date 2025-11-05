#include "combat_orchestration.h"
#include "entity.h"

namespace CombatOrchestration {
    void takeEnemyTurn(Entity& enemy, Entity& player) {
        // Opportunity for decision tree here
        enemy.m_combatSystem.attack(player.m_combatSystem);
    }

    void takePlayerTurn(Entity& player) {
        // Actions the player can take

        // Call narrator to narrate start of turn, and it should return the playerTurnDecision for us to action on
    }

    void runTurns(std::vector<Entity>& entities, Entity& player) {
        int aliveCount = 1; // Player is assumed alive
        bool isFirstPass = true;
        do {
            for (auto& entity : entities) {
                if (entity.getType() == 0) {
                    // Player turn
                    takePlayerTurn(player);
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
            isFirstPass = false;
        } while (aliveCount > 1);
        // Call narrator.roomCompleted ?
    }
}
