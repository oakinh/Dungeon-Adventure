#include "environment_objects.h"

int IRON_DOOR_HEALTH = 1000;
int STONE_DOOR_HEALTH = 500;
int WOOD_DOOR_HEALTH = 300;

Door::Door(Type type)
    : type { type } {
        switch (type) {
            case IRON:
                health = IRON_DOOR_HEALTH;
            case STONE:
                health = STONE_DOOR_HEALTH;
            case WOOD:
                health = WOOD_DOOR_HEALTH;
            default:
                break;
        }
    }