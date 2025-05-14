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
}

Game::~Game() {
    delete player;
    delete rival;
}

void Game::start() {
    std::string playerName, rivalName;

    std::cout << "\nOak: Hello there! Welcome to the world of POKEMON!\n";
    std::cout << "\n      My name is OAK!\n";
    std::cout << "\n      People call me the POKEMON PROF!\n";
    std::cout << "\n      This world is inhabited by creatures called POKEMON!\n";
    std::cout << "\n      For some people, POKEMON are pets. Others use them for fights.\n";
    std::cout << "\n      Myself...I study POKEMON as a profession.\n";
    std::cout << "\n      First, what is your name?\n\n";

    std::getline(std::cin, playerName);

    std::cout << "\nOak: Right! So your name is " << playerName << "!\n";
    std::cout << "\n      This is my grandson.\n";
    std::cout << "      He's been your rival since you were a baby. ...Erm, what is his name again?\n\n";

    std::getline(std::cin, rivalName);

    std::cout << "\nOak: That's right! I remember now! His name is " << rivalName << "!\n";
    std::cout << "\n      Your very own POKEMON legend is about to unfold!\n";
    std::cout << "      A world of dreams and adventures with POKEMON awaits! Let's go!\n";

    std::string starterChoice = chooseStarter();
    Pokemon* starter = createPokemon(starterChoice);

    player = new Trainer(playerName, starter);

    std::cout << "\nOak: You chose " << starter->getName() << "! A great choice for a new trainer like you, " << playerName << "!\n";

    std::cout << "\n      Your rival " << rivalName << " has chosen a Pokémon too!\n";
    exploreWorld();
}

std::string Game::chooseStarter() {
    std::string choice;
    std::cout << "\nOak: Now, choose your first Pokémon!\n\n";
    std::cout << "      Enter 1 for Charmander (Fire Type)\n";
    std::cout << "      Enter 2 for Bulbasaur (Grass Type)\n";
    std::cout << "      Enter 3 for Squirtle (Water Type)\n";

    while (true) {
        std::cout << "\nYour choice: ";
        std::cin >> choice;

        if (choice == "1") return "Charmander";
        if (choice == "2") return "Bulbasaur";
        if (choice == "3") return "Squirtle";
        std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
    }
}

void Game::exploreWorld() {
    int wildWins = 0;
    std::string choice;

    while (true) {
        std::cout << "\nWhat would you like to do?\n";
        std::cout << "1. Explore tall grass\n";
        std::cout << "2. Visit Pokémon Center\n";
        std::cout << "3. Exit Game\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice == "1") {
            if (handleWildBattle()) {
                wildWins++;
                if (wildWins >= 3) {
                    std::cout << "\nYou hear footsteps... your rival appears!\n";
                    std::cout << "Rival battle coming soon!\n";
                    break;
                }
            }
        } else if (choice == "2") {
            pokemonCenter();
        } else if (choice == "3") {
            std::cout << "\nThanks for playing!\n";
            break;
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }
}

bool Game::handleWildBattle() {
    std::vector<std::string> wildList = getWildPokemonNames();
    std::string wildName = wildList[rand() % wildList.size()];
    Pokemon* wild = createPokemon(wildName);
    Pokemon* playerPoke = player->getPokemon();

    std::cout << "\n🌿 A wild " << wild->getName() << " appeared!\n";

    while (!wild->isFainted() && !playerPoke->isFainted()) {
        // Show moves
        std::cout << "\nChoose your move:\n";
        const auto& moves = playerPoke->getMoveset();
        for (int i = 0; i < moves.size(); ++i) {
            std::cout << "  " << (i + 1) << ". " << moves[i].name
                      << " (" << typeToString(moves[i].type) << ", "
                      << moves[i].power << " power)\n";
        }

        int choice;
        std::cout << "Your choice: ";
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

        // Show current HP
        std::cout << "\n==============================\n";
        std::cout << "Your Pokémon:\n";
        std::cout << playerPoke->getName() << " HP:   " << hpBar(playerPoke->getCurrentHP(), playerPoke->getMaxHP()) << "\n";

        std::cout << "\nWild Pokémon:\n";
        std::cout << wild->getName() << " HP:   " << hpBar(wild->getCurrentHP(), wild->getMaxHP()) << "\n";
        std::cout << "==============================\n";

    }

    delete wild;
    return false;
}

void Game::pokemonCenter() {
    std::cout << "\nYou enter the Pokémon Center.\n";
    player->healPokemon();
    player->showStatus(); 
}


