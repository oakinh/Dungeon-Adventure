#include "entity.h"

std::string_view Entity::getName() const {
    return m_name;
}

std::ostream& operator<<(std::ostream& out, Entity::Type type) {
    out << Entity::getTypeName(type);
    return out;
}