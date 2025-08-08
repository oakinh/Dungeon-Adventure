#pragma once
#include <vector>
#include <string>
#include "inventory_system.h"

class CombatSystem {
    private:
        InventoryItem* weapon { nullptr };
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
        InventoryItem* getWeapon();
        int getHealth();
        int getAttack();
        void changeWeapon(const InventoryItem* weapon);
        int takeDamage(int damage);
        void reduceWeaponDurability(int durabilityAmount);
};