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
    std::cout << "The room is dark, and cold. Growling in the dark facing you is a ";
    const std::span enemies = room->getEnemies();
    for (int i { 0 }; i < enemies.size(); ++i) {
        std::cout << enemies[i].getType();
        if (i + 1 < enemies.size()) {
            std::cout << " and a ";
        } else {
            std::cout << ".";
        }
    }
}