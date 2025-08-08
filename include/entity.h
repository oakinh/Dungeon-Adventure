#pragma once
#include <string>
#include <vector>
#include "combat_system.h"
#include "inventory_system.h"

class Entity {
    private:
        InventorySystem m_inventorySystem {};
        CombatSystem m_combatSystem;

    public:
        Entity(int health, int attack, int defense)
            : m_combatSystem{ health, attack, defense }// Member initializer list
        {
        }
        int attack(Entity& target);
        int takeDamage(int damage);
};