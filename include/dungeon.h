#pragma once
#include <utility>
#include <vector>
#include <memory>
#include <span>

#include "inventory_items.h"
#include "entity.h"

class Dungeon;

class Room {
    friend class Dungeon;
    private:
        StatusEffect m_statusEffect {};
        std::vector<Entity> m_entities {};
        std::vector<InventoryItem> m_items {};
        std::unique_ptr<Room> m_nextRoom;
        int m_roomNum {};
    
    public:
        explicit Room(
            const StatusEffect statusEffect = {},
            std::vector<Entity> entities = {},
            std::vector<InventoryItem> items = {},
            const int roomNum = -1
            )
            : m_statusEffect(statusEffect)
            , m_entities(std::move(entities))
            , m_items(std::move(items))
            , m_roomNum(roomNum)
            {
            }

        Room* getNextRoom() const { return m_nextRoom.get(); }
        const std::vector<Entity>& getEntities() const { return m_entities; }
        std::span<const Entity> getEnemies() const; // Excludes the player
        const std::vector<InventoryItem>& getItems() const { return m_items; }
        int getRoomNum() const { return m_roomNum; }

        void setNextRoom(std::unique_ptr<Room> room) { m_nextRoom = std::move(room); }
        void enterRoom(Entity& entity); // Applies status effect
};

class Dungeon {
    private:
        std::unique_ptr<Room> m_rootRoom;
        int m_roomCount {};
        int m_minDifficulty {};
        int m_maxDifficulty {};

        Room* generateRooms(int roomCount, int minDifficulty, int maxDifficulty);
        void generateEnemies(int roomDifficulty, std::vector<Entity>& out_enemies);

    public:
        Dungeon(int roomCount, int minDifficulty, int maxDifficulty)
            : m_roomCount{ roomCount }
            , m_minDifficulty{ minDifficulty }
            , m_maxDifficulty{ maxDifficulty }
            {
                generateRooms(roomCount, minDifficulty, maxDifficulty);
            }
        
        Room* getRootRoom() { return m_rootRoom.get(); }
        void addRoom(Room* room);
};