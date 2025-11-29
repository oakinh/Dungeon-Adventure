#include "combat_orchestration.h"
#include "entity.h"
#include "narrator.h"

namespace CombatOrchestration {
    bool usePotion(ActionContext& ctx) {
        assert(ctx.initiator.getType() == Entity::PLAYER);
        Entity& player { ctx.initiator };
        size_t potionIndex { Narrator::askForPotionSelection(player) };
        InventoryItem* item { player.m_inventorySystem.findByIndex(potionIndex) };

        assert(item && "findByIndex returned nullptr");

        assert(std::holds_alternative<Potion>(*item) && "Selected item is not a potion");

        Potion& potion { std::get<Potion>(*item) };
        for (auto& statusEffect : potion.statusEffects) {
            ctx.target->m_combatSystem.applyStatusEffect(statusEffect);

        }

        return true;
    }
    bool throwRock(ActionContext& ctx) {
        return true;
    };
    bool throwExplosive(ActionContext& ctx) {
        return true;
    };
    bool run(ActionContext& ctx) {
        return true;
    };
    bool doNothing(ActionContext& ctx) {
        return true;
    };

    void takeEnemyTurn(Entity& enemy, Entity& player) {
        // TODO: Opportunity for decision tree here
        enemy.m_combatSystem.attack(player.m_combatSystem);
    }

    void takePlayerTurn(Room* room) {
        // TODO: Complete playerTurn logic
        // Actions the player can take
            // 1. Main weapon attack
            // 2. Run away
        // Call narrator to narrate start of turn, and it should return the playerTurnDecision for us to action on
        Entity& player { room->getPlayer() };
        PlayerDecisionsInfo playerDecisionsInfo { Narrator::runPlayerTurn(player) };
        if (playerDecisionsInfo.targetRequired) {
            Entity& target { Narrator::askForTarget(room->getEntitiesMutable() ) };
            ActionContext ctx { player, &target };
            playerDecisionsInfo.actionDecisionFcn(ctx);
        }
    }

    void runTurns(Room* room) {
        // TODO: Update StatusEffects on all entities, including player
        int aliveCount = 1; // Player is assumed alive
        bool isFirstPass = true;
        do {
            std::vector<Entity>& entities { room->getEntitiesMutable() };
            Entity& player { room->getPlayer() };

            for (auto& entity : room->getEntitiesMutable()) {
                if (entity.getType() == Entity::PLAYER) {
                    // Player turn
                    takePlayerTurn(room);
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
