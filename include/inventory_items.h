#pragma once
#include <string>
#include <variant>
#include <array>


class Entity;

struct StatusEffect {
    enum Stat {
        HEALTH,
        ATTACK,
        DEFENSE,
        AGILITY,
        MAX_STAT
    };
    bool isActive { false };
    Stat stat;
    int amount {};
    int remainingDuration {};
    // TODO: Figure out how to consistently apply effects, and decrement duration and remove effects
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
    const std::array<StatusEffect, StatusEffect::Stat::MAX_STAT> statusEffects {};
    std::string name {};
    int durability {};
};

struct Weapon {
    const std::array<StatusEffect::Stat, StatusEffect::Stat::MAX_STAT> statusEffects {};
    std::string name {};
    int durability {};
    bool equip();
    bool reduceDurability(int amount);
};

using InventoryItem = std::variant<Tool, Potion, Weapon>;