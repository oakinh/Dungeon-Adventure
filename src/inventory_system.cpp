#include "inventory_system.h"
// // Inventory Item
//         bool isActive { false };
//         void use();
//         void destroy();

// // Inventory System
//         bool addItem(InventoryItem& item);
//         void destroyItem(InventoryItem& item);


void InventoryItem::reduceDurability(int amount) {
    m_durability -= amount;
}