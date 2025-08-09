#pragma once
#include "inventory_system.h"

class CombatSystem {
    private:
        InventoryItem* m_weapon { nullptr };
        int m_health {};
        int m_attack {};
        int m_defense {};

    public:
        CombatSystem(int health, int attack, int defense) 
            : m_health { health }
            , m_attack { attack }
            , m_defense { defense }
        {
        }
    // Getters
        InventoryItem* getWeapon();
        int getHealth();
        int getAttack();

    // Mutators
        int attack(CombatSystem& target);
        void changeWeapon(InventoryItem* weapon);
        void takeDamage(int damage);
        void reduceWeaponDurability(int durabilityAmount);
};