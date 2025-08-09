#include "narrator.h"

void Narrator::welcomePlayer() {
    std::cout << "Welcome to the Dungeon, brave warrior." << '\n';
}

void Narrator::readDamage(const Entity& originator, const Entity& target, int damage) {
    damage > 0 
    ? std::cout << originator.getName() << " has attacked " << target.getName() << " for " << damage << " damage" << '\n'
    : std::cout << target.getName() << " dodged " << originator.getName() << "'s attack!" << '\n';
}