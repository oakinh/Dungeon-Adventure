#include <vector>

#include "entity.h"
#include "combat_system.h"

void takeEnemyTurn(Entity& enemy, Entity& player);
void takePlayerTurn(Entity& player);
void runTurns(std::vector<Entity>& entities);