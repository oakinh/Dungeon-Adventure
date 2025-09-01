#include <assert.h>

#include "inventory_items.h"
#include "combat_system.h"
#include "get_random_number.h"
#include "entity.h"

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
    target.takeDamage(damage);
    return damage;
}

void CombatSystem::changeWeapon(Weapon* weapon) {
    m_weapon = weapon;
}
void CombatSystem::takeDamage(int damage) {
    m_health -= damage;
    if (m_health <= 0) {
        // Make narrator aware of death
        this->m_owner->kill();
    }
}
void CombatSystem::reduceWeaponDurability(int durabilityAmount) {
    m_weapon->reduceDurability(durabilityAmount);
}

void CombatSystem::applyStatusEffect(const StatusEffect& statusEffect) {
    bool applied = false;
    for (auto& element : m_statusEffects) {
        if (element.stat == statusEffect.stat) {
            element.amount = statusEffect.amount;
            element.isActive = true;
            applied = true;
        }
    }
    assert(applied && "The statusEffect was successfully applied");
}