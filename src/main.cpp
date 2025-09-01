#include <iostream>
#include "entity.h"
#include "dungeon.h"
#include "combat_orchestration.h"
#include "narrator.h"

bool yesNoQuestion(std::string_view question) {
    std::cout << question;
    std::string answer {};
    std::cin >> answer;
    if (answer == "yes") return true;
    return false;
}

int main() {
    Narrator narrator = Narrator();
    narrator.welcomePlayer();
    std::cout << "Enter your name: ";
    std::string playerName {};
    std::cin >> playerName; // Shore up input handling

    Entity player { Entity::Type::PLAYER, 100, 25, 15, 20, 0 };
    
    std::cout << "Generating dungeon...\n";
    Dungeon dungeon = Dungeon(5, 10, 60);
    std::cout << "A dungeon has been generated!\nPrepare to die...\n";
    
    std::cout << "Would you like to enter the first room?\n";
    if (yesNoQuestion("Would you like to enter the first room?")) {
        dungeon.getRootRoom()->enterRoom(player);
        std::cout << "You've entered the dungeon. Good luck.\n";
    }

    Room* currentRoom = dungeon.getRootRoom();

    

    while (currentRoom->getNextRoom()) {
        narrator.readRoom(currentRoom);
        currentRoom = currentRoom->getNextRoom();
        narrator.readRoom(currentRoom);
    }

    // while (true) {
    //     runTurns(currentRoom->getEntities(), player)
    // }
    

    return 0;
}