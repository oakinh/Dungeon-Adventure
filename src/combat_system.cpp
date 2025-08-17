#include "inventory_items.h"
#include "combat_system.h"
#include "get_random_number.h"

// Getters
Weapon* CombatSystem::getWeapon() { // Maybe change the return type?
    return m_weapon;
}
int CombatSystem::getHealth() const {
    return m_health;
}
int CombatSystem::getAttack() const {
    return m_attack;
}

// Mutators
int CombatSystem::attack(CombatSystem& target) {
    int agilityMitigation{ getRandomNumber( 0, this->m_agility) };
    int damage{ this->m_attack - target.m_defense - agilityMitigation };
    damage = damage > 0 ? damage : 0;
    target.m_health -= damage;
    return damage;
}

void CombatSystem::changeWeapon(Weapon* weapon) {
    m_weapon = weapon;
}
void CombatSystem::takeDamage(int damage) {
    m_health -= damage;
}
void CombatSystem::reduceWeaponDurability(int durabilityAmount) {
    m_weapon->reduceDurability(durabilityAmount);
}

void CombatSystem::applyStatusEffect(const StatusEffect& statusEffect) {
    m_statusEffects.
}