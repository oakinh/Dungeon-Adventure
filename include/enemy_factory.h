#pragma once
#include "entity.h"

constexpr int GOBLIN_RATING { 10 };
constexpr int TROLL_RATING { 30 };
constexpr int ORC_RATING { 20 };
constexpr int BAT_RATING { 5 };

Entity createGoblin();
Entity createTroll();
Entity createOrc();