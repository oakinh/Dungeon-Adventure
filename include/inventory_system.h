#pragma once
#include <string>
#include <iostream>
#include <vector>

class InventoryItem {
    public:
        enum Type {
            WEAPON,
            TOOL,
            CONSUMABLE
        };
    private:
        Type m_type {};
        int m_durability {};

    public:
        bool isActive { false };
        void use();
        void destroy();

};

class InventorySystem {
    private:
        std::vector<InventoryItem> inventory{};
    public:
        bool addItem(InventoryItem& item);
        void destroyItem(InventoryItem& item);
};