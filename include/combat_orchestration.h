#include <vector>
#include <functional>

#include "combat_system.h"

class Entity;

namespace CombatOrchestration {
    enum class PlayerTurnDecisions {
        MAIN_WEAPON_ATTACK,
        USE_POTION,
        THROW_ROCK,
        THROW_EXPLOSIVE,
        RUN,
        DO_NOTHING,
        MAX_PLAYER_TURN_DECISIONS
    };

    using ActionDecisionFcn = std::function<bool(Entity, Entity)>; // Initiator, Target
    struct PlayerDecisionsInfo {
        std::string_view name;
        ActionDecisionFcn actionDecisionFcn;
    };

    static constexpr std::array<std::string_view, static_cast<size_t>(PlayerTurnDecisions::MAX_PLAYER_TURN_DECISIONS)>   {

    }

    void takeEnemyTurn(Entity& enemy, Entity& player);
    void takePlayerTurn(Entity& player);
    void runTurns(std::vector<Entity>& entities, Entity& player);
}
