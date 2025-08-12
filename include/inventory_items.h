#pragma once
#include <string>
#include <variant>
#include "environment_objects.h"

// 

struct StatusEffect {
    enum Stat {
        HEALTH,
        ATTACK,
        DEFENSE,
        AGILITY
    };
    Stat stat;
    int amount {};
};

struct Tool {
    enum Type {
        EXPLOSIVE,
        LOCKPICK,
        ROCK,
    };
    private:
        int EXPLOSIVE_DAMAGE = 500;
        int LOCKPICK_DAMAGE = 1;
        int ROCK_DAMAGE = 10;

    public:
        Type type {};
        std::string name {}; 
        int durability {};
        
        bool use(int target);
        
};

struct Potion {
    int durability {};
    StatusEffect statusEffect {};

};

using InventoryItem = std::variant<Tool, Potion>;