#pragma once
#include "combat_system.h"
#include "inventory_system.h"

class Entity {
    private:
        InventorySystem m_inventorySystem {};
        

    public:
        Entity(int health, int attack, int defense)
            : m_combatSystem{ health, attack, defense }
        {
        }

        CombatSystem m_combatSystem;
};