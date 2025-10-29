#include <span>
#include <memory>

#include "dungeon.h"
#include "entity.h"
#include "get_random_number.h"

void Room::enterRoom(Entity& entity) {
    entity.m_combatSystem.applyStatusEffect(m_statusEffect);
    m_entities.push_back(entity);
}

std::span<const Entity> Room::getEnemies() const {
    return { m_entities.begin(), m_entities.end() - 1 }; // This should exclude the player
}

void Dungeon::addRoom(Room* room) {
    std::unique_ptr<Room> node{room};
    if (!m_rootRoom) {
        m_rootRoom = std::move(node);
        return;
    }
    Room* curr = getRootRoom();
    while (curr->getNextRoom()) curr = curr->m_nextRoom.get();

    curr->m_nextRoom = std::move(node);
}

void Dungeon::generateEnemies(const int roomDifficulty, std::vector<Entity>& out_enemies) {
    int currentDifficultySum { 0 };

    while (currentDifficultySum < roomDifficulty) {
        int randomEnemyIndex = getRandomNumber(1, Entity::Type::MAX_TYPES - 1);
        int enemyRating = Entity::getRating(static_cast<Entity::Type>(randomEnemyIndex));
        bool shouldAddEnemy = true;
    
        while (enemyRating > roomDifficulty - currentDifficultySum) {
            if (randomEnemyIndex == 0) {
                // No more options, stop enemy generation
                return;
            }
            // Walk down the options, enemies are sorted by rating smallest to greatest
            --randomEnemyIndex;
            enemyRating = Entity::getRating(static_cast<Entity::Type>(randomEnemyIndex));
        }
        
        if (shouldAddEnemy) {
            std::cout << "randomEnemyIndex: " << randomEnemyIndex << '\n';
            Entity enemy { Entity::make(static_cast<Entity::Type>(randomEnemyIndex)) };
            std::cout << "Enemy name: " << enemy.getName() << '\n';
            out_enemies.push_back(Entity::make(static_cast<Entity::Type>(randomEnemyIndex)));
            std::cout << "Added enemy" << '\n';
            currentDifficultySum += enemyRating;
        }
    }
}

Room* Dungeon::generateRooms(int roomCount, int minDifficulty, int maxDifficulty) {
    // Create rooms

    // Fill with enemies
    Room* curr = nullptr;
    for (int i { 0 }; i < roomCount; ++i) {
        
        const int currentRoomDifficulty = ((i + 1) / roomCount) * maxDifficulty;
        
        std::vector<Entity> enemies {};
        generateEnemies(currentRoomDifficulty, enemies);
        std::cout << "Size of enemies: " << enemies.size() << '\n';
        Room newRoom = Room({}, enemies, {}, i);
        if (i == 0) m_rootRoom = std::make_unique<Room>(std::move(newRoom));

        if (!curr) {
            curr = this->getRootRoom();
        } else {
            curr->setNextRoom(std::make_unique<Room>(std::move(newRoom)));
        }
        std::cout << "Generated room number: " << i << '\n';
    }
    return nullptr;
    // Fill with loot
}