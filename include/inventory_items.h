#pragma once
#include <string>
#include <variant>

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
        constexpr static int EXPLOSIVE_DAMAGE = 500;
        constexpr static int LOCKPICK_DAMAGE = 1;
        constexpr static int ROCK_DAMAGE = 10;

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