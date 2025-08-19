#include "entity.h"
#include "enemy_factory.h"

Entity createGoblin() {
    return Entity{ Entity::Type::GOBLIN, 25, 10, 10, 5, GOBLIN_RATING};
}
Entity createTroll() {
    return Entity{ Entity::Type::TROLL, 75, 20, 25, 0, TROLL_RATING };
}
Entity createOrc() {
    return Entity{ Entity::Type::ORC, 50, 25, 15, 15, ORC_RATING};
}

Entity createBat() {
    return Entity{ Entity::Type::BAT, 5, 3, 1, 15, BAT_RATING };
}