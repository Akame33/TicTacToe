#pragma once
#include <iostream>
#include <string>

// On déclare la structure Player mais on ne définie pas
struct Player {
    std::string name{};
    char symbol{};
};

// On déclare la fonction permettant de "créer un joueur"
Player create_player(); 