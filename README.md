Pokémon Console Game

A simple text-based Pokémon-inspired adventure game written in C++. This game allows players to choose a starter Pokémon, battle wild Pokémon, and face off against a rival trainer.

🎮 Game Features

Choose Your Starter: Select from classic starter Pokémon - Charmander, Bulbasaur, or Squirtle
Wild Pokémon Encounters: Battle various wild Pokémon in tall grass
Rival Battles: Face off against your rival who chooses a Pokémon with type advantage
Pokémon Center: Heal your Pokémon to full health between battles
Turn-Based Combat: Use different moves with various power levels in battle

📋 Requirements

C++ compiler with C++11 support
Standard Library

🛠️ Compilation
To compile the game, use the following command:
bashg++ -std=c++11 main.cpp game.cpp pokemon.cpp trainer.cpp -o pokemon_game
🚀 How to Play

Run the compiled executable:
bash./pokemon_game

Follow the on-screen prompts to:

Enter your name
Name your rival
Choose your starter Pokémon (Charmander, Bulbasaur, or Squirtle)


Game Controls:

Enter number choices when prompted
Press Enter to advance dialogue
In battle, select moves by entering their corresponding number



🎲 Gameplay Guide

Starting the Game:

You'll be greeted by Professor Oak
Choose your name and your rival's name
Select one of three starter Pokémon


Exploring:

Navigate through Route 1
Enter tall grass to encounter wild Pokémon
Visit the Pokémon Center to heal your Pokémon


Battles:

Choose from your Pokémon's moves during your turn
Different moves have different types and power levels
Wild Pokémon will attack randomly with their available moves
If your Pokémon faints, the game ends


Progression:

After defeating 3 wild Pokémon, you'll encounter your rival
Defeat your rival to complete the game



🧩 Game Structure

main.cpp: Entry point for the game
game.cpp/h: Main game logic and flow
pokemon.cpp/h: Pokémon class definition and methods
trainer.cpp/h: Trainer class for the player and rival
pokemon_factory.h: Factory for creating different Pokémon
move.h: Defines the Move structure for Pokémon attacks
type.h and type_utils.h: Pokémon type enumeration and utilities
ui_utils.h: User interface utilities

🛣️ Future Enhancements
Possible enhancements for the game:

Type effectiveness system
Experience points and leveling
Multiple Pokémon in a party
Items and Pokéballs
More areas to explore

🎮 Enjoy the Game!

This simple Pokémon-inspired game offers a nostalgic experience reminiscent of the early Pokémon games. While it doesn't have all the features of the commercial games, it provides a fun introduction to the world of Pokémon through a console interface.
Have fun on your Pokémon adventure!
