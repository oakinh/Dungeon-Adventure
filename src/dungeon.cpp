#include "dungeon.h"

void Room::enterRoom(Entity& entity) {
    entity.m_combatSystem.applyStatusEffect(m_statusEffect);
    m_entities.push_back(entity);
}

Room* Dungeon::generateRooms(int roomCount, int minDifficulty, int maxDifficulty) {
    // Create rooms

    for (std::size_t i; i < roomCount; ++i) {
        int currentRoomDifficulty = ((i + 1) / roomCount) * maxDifficulty;
        
    }
    // Fill with enemies
    // Fill with loot
}