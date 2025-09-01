#include <vector>

#include "combat_system.h"

class Entity;

void takeEnemyTurn(Entity& enemy, Entity& player);
void takePlayerTurn(Entity& player);
void runTurns(std::vector<Entity>& entities);