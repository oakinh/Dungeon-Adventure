#include <iostream>
#include "entity.h"

int main() {
    std::cout << "Hello world!" << '\n';
    Entity player { 100, 10, 10};
    Entity goblin { 25, 5, 5};
    int damage = player.m_combatSystem.attack(goblin.m_combatSystem);
    std::cout << "Player has attacked goblin for " << damage << " damage" << '\n';
    std::cout << "Goblin has " << goblin.m_combatSystem.getHealth() << " health remaining!" << '\n';
    return 0;
}