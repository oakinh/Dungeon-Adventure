#pragma once
#include "inventory_system.h"

struct StatusDebuff {
    enum Stat {
        HEALTH,
        ATTACK,
        DEFENSE,
        AGILITY
    };
    int amount {};
};

class CombatSystem {
    private:
        InventoryItem* m_weapon { nullptr };
        int m_health {};
        int m_attack {};
        int m_defense {};
        int m_agility {};

    public:
        CombatSystem(int health, int attack, int defense, int agility) 
            : m_health { health }
            , m_attack { attack }
            , m_defense { defense }
            , m_agility { agility }
        {
        }
    // Getters
        InventoryItem* getWeapon();
        int getHealth() const;
        int getAttack() const;

    // Mutators
        int attack(CombatSystem& target);
        void changeWeapon(InventoryItem* weapon);
        void takeDamage(int damage);
        void reduceWeaponDurability(int durabilityAmount);
};