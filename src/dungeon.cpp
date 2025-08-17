#include "dungeon.h"

void Room::enterRoom(Entity& entity) {
    entity.m_combatSystem.applyStatusEffect(m_statusEffect);
}