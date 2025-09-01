#include "entity.h"

std::string_view Entity::getName() const {
    return m_name;
}

std::ostream& operator<<(std::ostream& out, Entity::Type type) {
    out << Entity::getTypeName(type);
    return out;
}

inline Entity Entity::createBat() {
    return Entity{ Entity::Type::BAT, 5, 3, 1, 15, Entity::getRating(Entity::Type::BAT) };
}

inline Entity Entity::createGoblin() {
    return Entity{ Entity::Type::GOBLIN, 25, 10, 10, 5, Entity::getRating(Entity::Type::GOBLIN)};
}

inline Entity Entity::createOrc() {
    return Entity{ Entity::Type::ORC, 50, 25, 15, 15, Entity::getRating(Entity::Type::ORC)};
}

inline Entity Entity::createTroll() {
    return Entity{ Entity::Type::TROLL, 75, 20, 25, 0, Entity::getRating(Entity::Type::TROLL) };
}