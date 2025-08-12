#pragma once
#include <vector>
#include "inventory_items.h"

// class Consumable {
//     private:
//         int m_durability {};

//     public:
//         bool isActive { false };
//         void use();
//         void destroy();
//         void reduceDurability(int amount);

// };

class InventorySystem {
    private:
        std::vector<InventoryItem> inventory{};
    public:
        bool addItem(InventoryItem& item);
        void removeFromInventory(InventoryItem& item);
        void destroyItem(InventoryItem& item);
};