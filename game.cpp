#include "game.h"
#include "pokemon.h"
#include "pokemon_factory.h"
#include <iostream>
#include <cstdlib>
#include <limits>
#include "pokemon_factory.h"
#include "type_utils.h"
#include "ui_utils.h"

Game::Game() {
    player = nullptr;
    rival = nullptr;
    rivalPokemon = nullptr;
}

Game::~Game() {
    delete player;
    delete rival;
}

void Game::start() {
    std::string playerName, rivalName;

    std::cout << "\n🟦==========================================🟦\n";
    std::cout << "\n🧑‍🔬 Professor Oak: Welcome to the world of POKEMON!\n";
    waitForEnter();

    std::cout << "🧢 My name is OAK, and people call me the POKEMON PROF.\n";
    waitForEnter();

    std::cout << "🌍 This world is inhabited by mysterious creatures called POKEMON.\n";
    waitForEnter();

    std::cout << "Some people keep them as pets, others use them in battles...\n";
    waitForEnter();

    std::cout << "I myself study POKEMON as a profession.\n";
    waitForEnter();

    std::cout << "🟦==========================================🟦\n";
    std::cout << "\n👤 First, what is your name, Trainer?\n\n";
    std::cout << "Your name: ";
    std::getline(std::cin, playerName);

    std::cout << "\n🧑‍🔬 Oak: Right! So your name is " << playerName << "!\n";
    waitForEnter();

    std::cout << "Now... this is my grandson. He's been your rival since you were both babies.\n";
    std::cout << "Hmm... what was his name again?\n\n";
    std::cout << "Rival's name: ";

    std::getline(std::cin, rivalName);

    std::cout << "\n🧑‍🔬 Oak: Ah yes! Now I remember — his name is " << rivalName << "!\n";
    waitForEnter();

    std::cout << "\n⚔️  Your very own POKEMON legend is about to unfold!\n";
    std::cout << "A world of dreams and adventures with POKEMON awaits — let's begin!\n";
    waitForEnter();

    std::string starterChoice = chooseStarter();
    waitForEnter();

    Pokemon* starter = createPokemon(starterChoice);
    player = new Trainer(playerName, starter);

    std::cout << "\n🟩===============================🟩\n";
    std::cout << "\n🎉 Your Starter Pokémon:\n";
    std::cout << "Name: " << starter->getName() << "\n";
    std::cout << "Type: " << typeToString(starter->getType()) << "\n";
    std::cout << "HP:   " << hpBar(starter->getCurrentHP(), starter->getMaxHP()) << "\n";
    std::cout << "\n🟩===============================🟩\n";
    waitForEnter();

    std::cout << "🧑‍🔬 Oak: You chose " << starter->getName() << "! A strong partner for a new Trainer like you, " << playerName << "!\n";
    waitForEnter();

    std::cout << "\n🧑‍🔬 Oak: Your rival " << rivalName << " has chosen a Pokémon too!\n";
    waitForEnter();

    std::cout << "📜 Oak: Before you go — here’s a tip...\n";
    std::cout << "🪵 Wild Pokémon live in tall grass. Be sure to heal up when needed!\n";
    waitForEnter();

    std::cout << "\n👣 You step outside into Route 1...\n";
    std::cout << "🌿 The grass is tall and rustling with movement.\n";
    waitForEnter();

    std::cout << "\n👀 Something’s watching you from the grass...\n";
    waitForEnter();

    if (handleWildBattle()) {
        postBattlePrompt();
    }

    exploreWorld();
}


std::string Game::chooseStarter() {
    std::string choice;

    std::cout << "\n🟥===============================🟥\n";
    std::cout << "\n🧑‍🔬 Oak: Now, choose your first Pokémon!\n";
    waitForEnter();

    std::cout << "Here are your options:\n";
    std::cout << "   1️⃣  🔥 Charmander — Fire Type\n";
    std::cout << "   2️⃣  🌿 Bulbasaur — Grass Type\n";
    std::cout << "   3️⃣  💧 Squirtle  — Water Type\n";
    std::cout << "\n🟥===============================🟥\n";

    while (true) {
        std::cout << "\nYour choice (1-3): ";
        std::cin >> choice;

        if (choice == "1") return "Charmander";
        if (choice == "2") return "Bulbasaur";
        if (choice == "3") return "Squirtle";

        std::cout << "❗ Invalid choice. Please enter 1, 2, or 3.\n";
    }
}


void Game::exploreWorld() {
    int wildWins = 0;
    std::string choice;

    std::cout << "\n🗺️  You are now on Route 1.\n";
    std::cout << "🌾 The grass is swaying... something may be lurking.\n";
    waitForEnter();

    while (true) {
        std::cout << "\n==============================\n";
        std::cout << "🧭 What would you like to do?\n";
        std::cout << "   1️⃣  Explore the tall grass\n";
        std::cout << "   2️⃣  🏥 Visit Pokémon Center\n";
        std::cout << "   3️⃣  ❌ Exit Game\n";
        std::cout << "==============================\n";
        std::cout << "\nYour choice: ";
        std::cin >> choice;

        if (choice == "1") {
            std::cout << "\n🌿 You step cautiously into the tall grass...\n";
            waitForEnter();

            if (handleWildBattle()) {
                wildWins++;

                if (wildWins >= 3) {
                    // ✅ Initialize rival & rivalPokemon if not already done
                    if (!rival) {
                        std::vector<std::string> options = getStarterOptions();
                        std::string playerStarter = player->getPokemon()->getName();
                        std::string rivalChoice;

                        for (const std::string& name : options) {
                            if (name != playerStarter) {
                                rivalChoice = name;
                                break;
                            }
                        }

                        rivalPokemon = createPokemon(rivalChoice);
                        rival = new Trainer("Rival", rivalPokemon);  // You can replace "Rival" with rivalName if stored
                    }

                    std::cout << "\n👣 You hear fast footsteps behind you...\n";
                    std::cout << "⚔️  Your rival " << rival->getName() << " appears and challenges you to a battle!\n";
                    waitForEnter();

                    if (handleRivalBattle()) {
                        std::cout << "\n🏆 Congratulations! You've defeated your rival!\n";
                        std::cout << "🎉 You are now a true Pokémon Trainer!\n";
                    } else {
                        std::cout << "\n💀 Your Pokémon fainted during the rival battle.\n";
                        std::cout << "Better luck next time!\n";
                    }

                    break;
                }

                postBattlePrompt();
            }
        } else if (choice == "2") {
            pokemonCenter();
        } else if (choice == "3") {
            std::cout << "\n🎮 Saving progress...\n";
            std::cout << "👋 Thanks for playing!\n";
            break;
        } else {
            std::cout << "❗ Invalid input. Please enter 1, 2, or 3.\n";
        }
    }
}


bool Game::handleWildBattle() {
    std::vector<std::string> wildList = getWildPokemonNames();
    std::string wildName = wildList[rand() % wildList.size()];
    Pokemon* wild = createPokemon(wildName);
    Pokemon* playerPoke = player->getPokemon();

    while (!wild->isFainted() && !playerPoke->isFainted()) {

        const auto& moves = playerPoke->getMoveset();
        int choice;

        std::cout << "\n🟨=============================🟨\n";
        std::cout << "🌿 A wild " << wild->getName() << " appeared!\n";
        std::cout << "🟨=============================🟨\n\n";

        std::cout << "🔥 Your Pokémon: " << playerPoke->getName() << "\n";
        std::cout << "HP:   " << hpBar(playerPoke->getCurrentHP(), playerPoke->getMaxHP()) << "\n\n";

        std::cout << "🧪 Wild Pokémon: " << wild->getName() << "\n";
        std::cout << "HP:   " << hpBar(wild->getCurrentHP(), wild->getMaxHP()) << "\n\n";

        std::cout << "🕹️  What will " << playerPoke->getName() << " do?\n\n";
        for (int i = 0; i < moves.size(); ++i) {
            std::cout << "   " << (i + 1) << "️⃣  " << moves[i].name
                    << " (" << typeToString(moves[i].type) << ", "
                    << moves[i].power << ")\n";
        }
        std::cout << "\nYour choice: ";
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > moves.size()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid move! You miss your turn!\n";
        } else {
            const Move& selected = moves[choice - 1];
            std::cout << playerPoke->getName() << " used " << selected.name << "!\n";
            wild->takeDamage(selected.power);
        }

        if (wild->isFainted()) {
            std::cout << "\n🎉 You defeated the wild " << wild->getName() << "!\n";
            delete wild;
            return true;
        }

        // Wild Pokémon turn
        const auto& wildMoves = wild->getMoveset();
        Move wildMove = wildMoves[rand() % wildMoves.size()];
        std::cout << "The wild " << wild->getName() << " used " << wildMove.name << "!\n";
        playerPoke->takeDamage(wildMove.power);

        if (playerPoke->isFainted()) {
            std::cout << "\n💀 Your " << playerPoke->getName() << " fainted!\n";
            std::cout << "Game Over. Better luck next time!\n";
            delete wild;
            exit(0);
        }




    }

    delete wild;
    return false;
}

void Game::postBattlePrompt() {
    std::string choice;

    std::cout << "\n🟩===============================🟩\n";
    std::cout << "🎊 Victory! The wild Pokémon has fainted.\n";
    std::cout << "🟩===============================🟩\n";

    while (true) {
        std::cout << "\n🧭 What would you like to do next?\n";
        std::cout << "   1️⃣  Continue exploring\n";
        std::cout << "   2️⃣  🏥 Visit Pokémon Center\n";
        std::cout << "\nYour choice: ";
        std::cin >> choice;

        if (choice == "1") {
            std::cout << "\n🌿 You venture deeper into the tall grass...\n";
            break;
        } else if (choice == "2") {
            std::cout << "\n🏥 Heading to the nearest Pokémon Center...\n";
            pokemonCenter();
            break;
        } else {
            std::cout << "❗ Invalid choice. Please enter 1 or 2.\n";
        }
    }
}


void Game::pokemonCenter() {
    std::cout << "\n🏥 You enter the Pokémon Center...\n";
    waitForEnter();

    std::cout << "👩‍⚕️ Nurse Joy: Welcome to the Pokémon Center!\n";
    std::cout << "💉 Let me heal your Pokémon back to full health.\n";

    waitForEnter();

    std::cout << "\n✨ Healing in progress...\n";
    std::cout << "🔄 HP being restored...\n";
    waitForEnter();

    player->healPokemon();

    std::cout << "\n✅ " << player->getPokemon()->getName() << "'s HP has been fully restored!\n";
    player->showStatus();

    std::cout << "\n👩‍⚕️ Nurse Joy: We hope to see you again!\n";
    waitForEnter();
}

bool Game::handleRivalBattle() {
    // Create rival's Pokémon if not already created
    if (!rivalPokemon) {
        std::vector<std::string> options = getStarterOptions();
        std::string playerStarter = player->getPokemon()->getName();
        std::string rivalChoice;

        // Rival picks a different starter
        for (const std::string& name : options) {
            if (name != playerStarter) {
                rivalChoice = name;
                break;
            }
        }

        rivalPokemon = createPokemon(rivalChoice);
        rival = new Trainer(rivalName, rivalPokemon);  // You may store rivalName if you want
    }

    Pokemon* playerPoke = player->getPokemon();
    Pokemon* enemy = rival->getPokemon();

    std::cout << "\n🟥===============================🟥\n";
    std::cout << "⚔️  Rival Battle Begins!\n";
    std::cout << playerPoke->getName() << " vs. " << enemy->getName() << "!\n";
    std::cout << "🟥===============================🟥\n";
    waitForEnter();

    while (!playerPoke->isFainted() && !enemy->isFainted()) {
        const auto& playerMoves = playerPoke->getMoveset();
        const auto& rivalMoves = enemy->getMoveset();
        int choice;

        std::cout << "\n🔥 Your Pokémon: " << playerPoke->getName() << "\n";
        std::cout << "HP:   " << hpBar(playerPoke->getCurrentHP(), playerPoke->getMaxHP()) << "\n\n";

        std::cout << "🧪 Rival's Pokémon: " << enemy->getName() << "\n";
        std::cout << "HP:   " << hpBar(enemy->getCurrentHP(), enemy->getMaxHP()) << "\n\n";

        std::cout << "🕹️  Choose your move:\n";
        for (int i = 0; i < playerMoves.size(); ++i) {
            std::cout << "   " << (i + 1) << "️⃣  " << playerMoves[i].name
                      << " (" << typeToString(playerMoves[i].type) << ", "
                      << playerMoves[i].power << ")\n";
        }

        std::cout << "\nYour choice: ";
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > playerMoves.size()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "❌ Invalid move! You miss your turn!\n";
        } else {
            const Move& selected = playerMoves[choice - 1];
            std::cout << playerPoke->getName() << " used " << selected.name << "!\n";
            enemy->takeDamage(selected.power);
        }

        if (enemy->isFainted()) {
            std::cout << "\n🎉 You defeated your rival's " << enemy->getName() << "!\n";
            return true;
        }

        // Rival attacks
        Move rivalMove = rivalMoves[rand() % rivalMoves.size()];
        std::cout << "The rival's " << enemy->getName() << " used " << rivalMove.name << "!\n";
        playerPoke->takeDamage(rivalMove.power);

        if (playerPoke->isFainted()) {
            std::cout << "\n💀 Your " << playerPoke->getName() << " fainted!\n";
            return false;
        }
    }

    return false;
}