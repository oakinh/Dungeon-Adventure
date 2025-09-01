#pragma once
#include <ostream>
#include <string_view>

#include "combat_system.h"
#include "inventory_system.h"

class Entity {
    public:
    enum Type {
        PLAYER,
        BAT,
        GOBLIN,
        ORC,
        TROLL,
        MAX_TYPES
    };
    static constexpr int ENEMY_STARTING_INDEX = 1;
    static constexpr int ENEMY_COUNT = Entity::Type::MAX_TYPES - 1;
    
    static constexpr std::array<std::string_view, ENEMY_COUNT> typeStrings {
        "Bat",
        "Goblin",
        "Orc",
        "Troll"
    };
    
    private:
        bool m_isAlive = true;
        InventorySystem m_inventorySystem {};
        std::string_view m_name {};
        int m_rating {}; // Used to calculate the difficulty of a room
        Type m_type;

    public:
        Entity(Type type, int health, int attack, int defense, int agility, int rating)
            : m_type{type}
            , m_combatSystem{ health, attack, defense, agility, this }
            , m_rating{ rating }
        {
        }

        CombatSystem m_combatSystem;
    // Static
        static std::string_view getTypeName(Entity::Type type) {
            return Entity::typeStrings[type];
        }
    
    // Getters
        std::string_view getName() const;
        bool getIsAlive() const { return m_isAlive; };
        const Type getType() const { return m_type; };
    
    // Mutators
        void assignName(std::string_view name);
        void kill() { m_isAlive = false; };
};

std::ostream& operator<<(std::ostream& out, Entity::Type type);