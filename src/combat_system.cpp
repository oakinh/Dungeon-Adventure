#include "combat_system.h"

// Getters
InventoryItem* CombatSystem::getWeapon() { // Maybe change the return type?
    return m_weapon;
}
int CombatSystem::getHealth() {
    return m_health;
}
int CombatSystem::getAttack() {
    return m_attack;
}

// Mutators
int CombatSystem::attack(CombatSystem& target) {
    const int damage = this->m_attack - target.m_defense;
    target.m_health -= damage;
    return damage;
}

void CombatSystem::changeWeapon(InventoryItem* weapon) {
    m_weapon = weapon;
}
void CombatSystem::takeDamage(int damage) {
    m_health -= damage;
}
void CombatSystem::reduceWeaponDurability(int durabilityAmount) {
    m_weapon->reduceDurability(durabilityAmount);
}