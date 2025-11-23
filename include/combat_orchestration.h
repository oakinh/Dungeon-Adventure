#pragma once
#include <vector>
#include <functional>
#include <cassert>
#include "dungeon.h"
#include "combat_system.h"
#include "entity.h"

class Entity;

namespace CombatOrchestration {

    enum class PlayerTurnDecisions {
        CURRENT_WEAPON_ATTACK,
        USE_POTION,
        THROW_ROCK,
        THROW_EXPLOSIVE,
        RUN,
        DO_NOTHING,
        MAX_PLAYER_TURN_DECISIONS
    };

    struct ActionContext {
        // Required
        Entity& initiator;

        // Optional
        Entity* target = nullptr;
        Room* room = nullptr;
    };

    //using ActionDecisionFcn = std::function<bool(Entity&, Entity&)>; // Initiator, Target
    using ActionDecisionFcn = bool(*)(ActionContext&);
    struct PlayerDecisionsInfo {
        std::string_view name;
        ActionDecisionFcn actionDecisionFcn;
    };

    // *--------------------------------*
    // Player Action Decision Functions
    // *--------------------------------*
    inline bool currentWeaponAttack(ActionContext& ctx) {
        assert(!ctx.initiator.isEnemy() && "Enemy cannot be the initator of currentWeaponAttack");
        assert((ctx.target) && "Target must not be null for currentWeaponAttack");
        int damage { ctx.initiator.m_combatSystem.attack(ctx.target->m_combatSystem) };
        return damage > 0;
    }

    bool usePotion(ActionContext& ctx);
    bool throwRock(ActionContext& ctx);
    bool throwExplosive(ActionContext& ctx);
    bool run(ActionContext& ctx);
    bool doNothing(ActionContext& ctx);


    static constexpr std::array<PlayerDecisionsInfo, static_cast<size_t>(PlayerTurnDecisions::MAX_PLAYER_TURN_DECISIONS)> kInfo {{
        { "Current Weapon Attack",  currentWeaponAttack},
        { "Use Potion", usePotion },
        { "Throw Rock", throwRock },
        { "Throw Explosive", throwExplosive },
        { "Run", run },
        { "Do Nothing", doNothing }
    }};

    void takeEnemyTurn(Entity& enemy, Entity& player);
    void takePlayerTurn(Entity& player);
    void runTurns(std::vector<Entity>& entities, Entity& player);
}
