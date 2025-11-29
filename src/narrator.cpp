#include <iostream>
#include <variant>
#include <limits>
#include "narrator.h"

#include "combat_orchestration.h"
#include "entity.h"

size_t Narrator::getValidSelection(const std::pair<size_t, size_t>& inclusiveBounds) {
    while (true) {
        int selection { takeIntSelection() };
        --selection; // For zero-based array
        size_t selectionUZ { static_cast<size_t>(selection) };
        if (selectionUZ >= inclusiveBounds.first && selectionUZ <= inclusiveBounds.second) {
            return selectionUZ;
        }
    }
}

void Narrator::welcomePlayer() {
    std::cout << "Welcome to the Dungeon, brave warrior." << '\n';
}

int Narrator::takeIntSelection() {
    int selection;

    while (true) {
        if (std::cin >> selection) return selection;

        std::cout << "Invalid number. Try again.\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void Narrator::readDamage(const Entity& originator, const Entity& target, int damage) {
    damage > 0 
    ? std::cout 
        << originator.getName() 
        << " has attacked " 
        << target.getName() 
        << " for " 
        << damage 
        << " damage" 
        << '\n'
    : std::cout 
        << target.getName() 
        << " dodged " 
        << originator.getName() 
        << "'s attack!" 
        << '\n';
}

void Narrator::readRoom(const Room* room) {
    std::cout << "Room " << room->getRoomNum() << ":" << '\n';
    std::cout << "The room is dark, and cold. ";

    const std::vector<Entity>& enemies = room->getEntities();
    if (enemies.empty()) {
        std::cout << "It's empty.\n";
    } else {
        std::cout << "Growling before you is a ";
    }
    for (int i { 0 }; i < enemies.size(); ++i) {
        std::cout << enemies[i].getType();
        if (i + 1 < enemies.size()) {
            std::cout << " and a ";
        } else {
            std::cout << ".\n";
        }
    }
}

size_t Narrator::askForPotionSelection(const Entity& player) {
    std::cout << "You've chosen to throw a potion. Please select one from the list below by entering it's listed number: \n";
    const auto& inv { player.m_inventorySystem.inventory };
    std::unordered_map<size_t, size_t> displayNumToIndex {};
    size_t displayNum { 1 };
    for (size_t i { 0 }; i < inv.size(); ++i) {
        const auto& invItem = inv[i];
        std::visit([&displayNum, &displayNumToIndex, i](const auto& obj) {
            using T = std::decay_t<decltype(obj)>;
            if constexpr (std::is_same_v<T, Potion>) {
                displayNumToIndex.emplace(displayNum, i);
                std::cout << displayNum << '.' << obj.name << '\n';
                ++displayNum;
            }
        }, invItem);
    }

    auto it = displayNumToIndex.end();
    do {
        int selection = { takeIntSelection() };
        it = displayNumToIndex.find(selection);
    } while (it == displayNumToIndex.end());

    return it->second;
}



const CombatOrchestration::PlayerDecisionsInfo& Narrator::runPlayerTurn(Entity& player) {
    std::cout << player.getName() << ", it's your turn. Select your choice of action from the options below by entering its list number: \n";
    for (size_t i { 0 }; i < CombatOrchestration::kInfoDecisions.size(); ++i) {
        std::cout << i + 1 << ". " << CombatOrchestration::kInfoDecisions[i].name;
    }
    while (true) {
        int selection { takeIntSelection() };
        --selection; // For zero-based array
        size_t selectionUZ { static_cast<size_t>(selection) };
        if (selectionUZ > 0 && selectionUZ < CombatOrchestration::kInfoDecisions.size()) {
            return CombatOrchestration::kInfoDecisions[selectionUZ];
        }
    }
}

void Narrator::readStatusEffectApplied(StatusEffect& statusEffect, Entity& entity) {
    std::cout
        << "A status effect of "
        << statusEffect.amount
        << " on " << statusEffect.stat
        << " has been applied to "
        << entity.getName() << " the "
        << Entity::getTypeStr(entity.getType())
        << '\n';
}

Entity& Narrator::askForTarget(std::vector<Entity>& entities) {
    std::cout << "You've selected an action that requires a target.\nPlease select one from the options below by entering its list number.\n";
    size_t displayNum { 1 };
    for (size_t i { 0 }; i < entities.size(); ++i) {
        std::cout << displayNum << ". " << Entity::getTypeStr(entities[i].getType());
        size_t selectionUZ { getValidSelection({ 1, entities.size() - 1}) };
        return entities[selectionUZ];
    }
}

