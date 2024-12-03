#pragma once
#include <iostream>
#include <string>

// On déclare mais on ne définie pas
struct Player {
    std::string name{};
    char symbol{};
};

Player create_player(); 