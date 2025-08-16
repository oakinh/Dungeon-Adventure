#include "inventory_items.h"
#include "environment_objects.h"


// Tool
bool Tool::use(int target) {
    // switch (type) {
    //     case LOCKPICK:
    //         if (target == DOOR) {
    //             DOOR.open();
    //         }
    //         break;
    //     case EXPLOSIVE:
    //     case ROCK:
    //     default:
    // }
    
    return true;
}

// Potion
bool Potion::toss() {
    return true;
}

// Weapon
bool Weapon::equip() {
    return true;

}
bool Weapon::reduceDurability(int amount) {
    return true;
}