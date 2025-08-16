#pragma once
#include <vector>
#include "inventory_items.h"
#include "entity.h"


class Room {
    private:
        StatusEffect statusEffect {};
        std::vector<Entity> entities {};
        std::vector<InventoryItem> items {};
        Room* nextRoom {};
    
    public:
        Room* getNextRoom() const;
        std::vector<Entity>& getEntities() const;
        std::vector<InventoryItem>& getItems() const;
        
        void enterRoom(Entity& entity); // Applies status effect


};