#include "entity.h"

Entity createGoblin() {
    return Entity{ 25, 10, 10, 5};
}
Entity createTroll() {
    return Entity{75, 20, 25, 0 };
}
Entity createOrc() {
    return Entity{50, 25, 15, 15};
}