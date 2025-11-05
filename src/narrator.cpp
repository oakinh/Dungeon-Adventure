#include <iostream>

#include "narrator.h"
#include "entity.h"

void Narrator::welcomePlayer() {
    std::cout << "Welcome to the Dungeon, brave warrior." << '\n';
}

void Narrator::readDamage(const Entity& originator, const Entity& target, int damage) {
    damage > 0 
    ? std::cout 
        << originator.getName() 
        << " has attacked " 
        << target.getName() 
        << " for " 
        << damage 
        << " damage" 
        << '\n'
    : std::cout 
        << target.getName() 
        << " dodged " 
        << originator.getName() 
        << "'s attack!" 
        << '\n';
}

void Narrator::readRoom(const Room* room) {
    std::cout << "Room " << room->getRoomNum() << ":" << '\n';
    std::cout << "The room is dark, and cold. ";

    const std::vector<Entity>& enemies = room->getEntities();
    if (enemies.empty()) {
        std::cout << "It's empty.\n";
    } else {
        std::cout << "Growling before you is a ";
    }
    for (int i { 0 }; i < enemies.size(); ++i) {
        std::cout << enemies[i].getType();
        if (i + 1 < enemies.size()) {
            std::cout << " and a ";
        } else {
            std::cout << ".\n";
        }
    }
}

void Narrator::runPlayerTurn(Entity& player) {
    std::cout << player.getName() << ", it's your turn."
}