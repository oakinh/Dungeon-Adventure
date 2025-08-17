#pragma once
#include <vector>
#include "inventory_items.h"
#include "entity.h"


class Room {
    private:
        StatusEffect m_statusEffect {};
        std::vector<Entity> m_entities {};
        std::vector<InventoryItem> m_items {};
        Room* m_nextRoom = nullptr;
    
    public:
        Room(StatusEffect statusEffect, std::vector<Entity> entities, std::vector<InventoryItem> items)
            : m_statusEffect(statusEffect)
            , m_entities(entities)
            , m_items(items)
            {
            }

        Room* getNextRoom() { return m_nextRoom; }
        const std::vector<Entity>& getEntities() const { return m_entities; }
        const std::vector<InventoryItem>& getItems() const { return m_items; }

        void setNextRoom(Room* room) { m_nextRoom = room; }
        void enterRoom(Entity& entity); // Applies status effect


};