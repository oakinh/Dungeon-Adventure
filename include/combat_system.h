#pragma once
#include <array>
#include "inventory_items.h"

struct Weapon;
class Entity;

class CombatSystem {
    private:
        Weapon* m_weapon { nullptr };
        int m_health {};
        int m_attack {};
        int m_defense {};
        int m_agility {};
        std::array<StatusEffect, StatusEffect::MAX_STAT> m_statusEffects {};
        Entity* m_owner {};

    public:
        CombatSystem(int health, int attack, int defense, int agility, Entity* owner) 
            : m_health { health }
            , m_attack { attack }
            , m_defense { defense }
            , m_agility { agility }
            , m_owner { owner }
        {
            for (size_t i = 0; i < StatusEffect::MAX_STAT; ++i) {
                // Initialize array with one of each types of StatusEffects
                m_statusEffects[i].stat = static_cast<StatusEffect::Stat>(i);
            }
        }
    // Getters
        Weapon* getWeapon();
        int getHealth() const;
        int getAttack() const;
        int getDefense() const;
        int getAgility() const;

    // Mutators
        int attack(CombatSystem& target);
        void changeWeapon(Weapon* weapon);
        void takeDamage(int damage);
        void reduceWeaponDurability(int durabilityAmount);
        void applyStatusEffect(const StatusEffect& statusEffect);
};