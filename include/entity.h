#pragma once
#include <string_view>

#include "combat_system.h"
#include "inventory_system.h"

class Entity {
    public:
    enum Type {
        PLAYER,
        ORC,
        GOBLIN,
        TROLL,
        BAT,
        MAX_TYPES
    };
    private:
        InventorySystem m_inventorySystem {};
        std::string_view m_name {};
        int m_rating {}; // Used to calculate the difficulty of a room
        Type m_type;

    public:
        Entity(Type type, int health, int attack, int defense, int agility, int rating)
            : m_type{type}
            , m_combatSystem{ health, attack, defense, agility }
            , m_rating{ rating }
        {
        }

        CombatSystem m_combatSystem;

        std::string_view getName() const;
        void assignName(std::string_view name);
};