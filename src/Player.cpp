#include "Player.h"
#include <iostream>

Player create_player() {
    Player player; // instance de la structure Player
    std::cout << "Entrez le nom du joueur : ";
    std::cin >> player.name;
    std::cout << "Choisissez un symbole (X ou O) : ";
    std::cin >> player.symbol;
    return player;
}