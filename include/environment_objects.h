#pragma once
#include <variant>

class Door {
    enum Type {
        IRON,
        WOOD,
        STONE,
    };
    public:
        int health {};
        Type type {};
        Door(Type type);
};

using EnvironmentObject = std::variant<Door>;