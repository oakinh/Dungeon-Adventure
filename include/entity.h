#pragma once
#include <cassert>
#include <functional>
#include <iostream>
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

    using FactoryFn = Entity(*)();
    //using FactoryFn = std::function<Entity>;
    struct TypeInfo {
        std::string_view name;
        int rating;
        bool isEnemy;
        FactoryFn factory;
    };

    static Entity createBat();
    static Entity createGoblin();
    static Entity createOrc();
    static Entity createTroll();

    static constexpr std::array<TypeInfo, static_cast<size_t>(Type::MAX_TYPES)> kInfo = {{
        { "Player",  0, false, nullptr },
        { "Bat",     5, true, &Entity::createBat },
        { "Goblin", 10, true, &Entity::createGoblin },
        { "Orc",    20, true, &Entity::createOrc },
        { "Troll",  30, true, &Entity::createTroll },
    }};
    
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
        static constexpr std::string_view getTypeName(Type type) {
            return kInfo[static_cast<size_t>(type)].name;
        }

        static constexpr bool isEnemy(Type type) {
            return kInfo[static_cast<size_t>(type)].isEnemy;
        }

        static constexpr int getRating(Type type) {
            return kInfo[static_cast<size_t>(type)].rating;
        }

        static Entity make(Type type) {
            assert(type < Type::MAX_TYPES);
            auto& info = kInfo[static_cast<size_t>(type)];
            if (!info.factory) {
                std::cout << "No factory method available\n";
                return Entity{ Entity::Type::PLAYER, 100, 25, 15, 20, 0 };
            }
            return info.factory();            
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