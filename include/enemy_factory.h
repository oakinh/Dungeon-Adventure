#pragma once

#include <array>
#include "entity.h"

namespace Enemies {
    constexpr int LAST_INDEX = Entity::ENEMY_COUNT - 1;

    constexpr int BAT_RATING { 5 };
    constexpr int GOBLIN_RATING { 10 };
    constexpr int ORC_RATING { 20 };
    constexpr int TROLL_RATING { 30 };

    // Subtract one to disregard the player as an option
    constexpr std::array<int, Entity::ENEMY_COUNT> enemyRatings { 
        BAT_RATING, 
        GOBLIN_RATING, 
        ORC_RATING, 
        TROLL_RATING,  
    };

    using EnemyFactoryFunction = Entity(*)(void);

    Entity createBat();
    Entity createGoblin();
    Entity createOrc();
    Entity createTroll();

    constexpr std::array<EnemyFactoryFunction, Entity::ENEMY_COUNT> factoryFunctions {
        createBat,
        createGoblin,
        createOrc,
        createTroll
    };

    static_assert(enemyRatings.size() == Entity::ENEMY_COUNT, "Every Entity type that's an enemy must be given an enemyRating\n");
    static_assert(factoryFunctions.size() == Entity::ENEMY_COUNT, "Every Entity type that's an enemy must be given a factoryFunction\n");
}
