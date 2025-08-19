#include <iostream>
#include "entity.h"
#include "enemy_factory.h"

int main() {
    std::cout << "Welcome to the Dungeon, brave warrior." << '\n';
    std::cout << "Enter your name: ";
    std::string playerName {};
    std::cin >> playerName; // Shore up input handling

    Entity player { Entity::Type::PLAYER, 100, 25, 15, 20, 0 };
    Entity goblin { createGoblin()};
    int damage = player.m_combatSystem.attack(goblin.m_combatSystem);
    std::cout << "Player has attacked goblin for " << damage << " damage" << '\n';
    std::cout << "Goblin has " << goblin.m_combatSystem.getHealth() << " health remaining!" << '\n';
    return 0;
}