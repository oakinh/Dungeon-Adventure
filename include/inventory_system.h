#pragma once
#include <vector>
#include "inventory_items.h"

class InventorySystem {
    private:
        std::vector<InventoryItem> inventory{};
    public:
        bool addItem(InventoryItem& item);
        void removeFromInventory(InventoryItem& item);
        void destroyItem(InventoryItem& item);
};