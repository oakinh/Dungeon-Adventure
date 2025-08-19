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

class Dungeon {
    private:
        Room* m_root = nullptr;
        int m_roomCount {};
        int m_minDifficulty {};
        int m_maxDifficulty {};

        Room* generateRooms(int roomCount, int minDifficulty, int maxDifficulty);

    public:
        Dungeon(int roomCount, int minDifficulty, int maxDifficulty)
            : m_roomCount{ roomCount }
            , m_minDifficulty{ minDifficulty }
            , m_maxDifficulty{ maxDifficulty }
            {
                generateRooms(roomCount, minDifficulty, maxDifficulty);
            }
        
        Room* getRootRoom() { return m_root; };
};