#pragma once
#include "combat_system.h"
#include "inventory_system.h"

class Entity {
    private:
        InventorySystem m_inventorySystem {};
        

    public:
        Entity(int health, int attack, int defense, int agility)
            : m_combatSystem{ health, attack, defense, agility }
        {
        }

        CombatSystem m_combatSystem;
};