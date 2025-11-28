#pragma once
#include <deque>
#include "inventory_items.h"

class Narrator;

class InventorySystem {
    private:
        std::deque<InventoryItem> inventory{};
    public:
        friend Narrator;
        bool addItem(InventoryItem& item);
        void removeFromInventory(InventoryItem& item);
        void destroyItem(InventoryItem& item);
        InventoryItem* findByIndex(size_t i);
};