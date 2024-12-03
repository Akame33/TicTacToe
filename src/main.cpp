#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Plateau.h"

// le menu
int menu()
{
    int mode;
    std::cout << "Jeu TicTacToe - Morpion" << std::endl;
    std::cout << "Choisissez un mode de jeu : " << std::endl;
    std::cout << "1. Deux joueurs " << std::endl;
    std::cout << "2. Un joueur contre l'IA " << std::endl;
    while (mode != 1 && mode != 2)
    {
        std::cout << "Choix invalide. Veuillez sélectionner 1 ou 2 : ";
        std::cin >> mode;
    }
    return mode;
}

// tour de jeu
void your_turn(char board[9], Player player)
{
    int choice;
    std::cout << player.name << ", choisissez une case libre : ";
    std::cin >> choice;
    while (board[choice - 1] != '.')
    {
        std::cout << "Cette case est déjà prise. Choisissez une autre case...";
        std::cin >> choice;
    }
    board[choice - 1] = player.symbol;
}

// Tour de l'IA
void ia_turn(char board[9], Player ia, char opponent_symbol)
{
    std::cout << "C'est au tour de " << ia.name << std::endl;

    // Vérifier les possibilités de blocage
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == '.') // Si la case est vide
        {
            // Simuler un coup de l'adversaire
            board[i] = opponent_symbol;
            if (victory(board, opponent_symbol))
            {
                // Bloquer si l'adversaire gagne
                board[i] = ia.symbol;
                std::cout << ia.name << " bloque la case " << (i + 1) << std::endl;
                return;
            }
            // Annuler la simulation
            board[i] = '.';
        }
    }

    // Si aucun blocage n'est nécessaire, choisir une case aléatoire
    int choice;
    do
    {
        choice = rand() % 9;
    } while (board[choice] != '.');
    board[choice] = ia.symbol;
    std::cout << ia.name << " a choisi la case " << (choice + 1) << std::endl;
}

int main()
{
    srand(time(0));
    int mode = menu();

    // Création des joueurs
    Player player1 = create_player();
    Player player2;

    if (mode == 1)
    {
        player2 = create_player(); // Supprimé la redéclaration redondante
        std::cout << "Joueur 1 : " << player1.name << " joue avec " << player1.symbol << std::endl;
        std::cout << "Joueur 2 : " << player2.name << " joue avec " << player2.symbol << std::endl;
    }
    else
    {
        player2.name = "IA";
        player2.symbol = (player1.symbol == 'X') ? 'O' : 'X';

        std::cout << "Joueur 1 : " << player1.name << " joue avec " << player1.symbol << std::endl;
        std::cout << "IA : " << player2.name << " joue avec " << player2.symbol << std::endl;
    }

    // Initialisation du plateau
    char board[9] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    draw_game_board(board);

    Player current_player = player1;
    for (int i = 0; i < 9; ++i)
    {
        std::cout << "C'est au tour de " << current_player.name << std::endl;

        if (mode == 2 && current_player.name == "IA")
        {
            ia_turn(board, player2, player1.symbol); // Passer le symbole de l'adversaire
        }
        else
        {
            your_turn(board, current_player);
        }

        draw_game_board(board);

        if (victory(board, current_player.symbol))
        {
            std::cout << current_player.name << " a gagné !" << std::endl;
            return 0;
        }

        if (current_player.symbol == player1.symbol) {
            current_player = player2;
        }
        else {
            current_player = player1;
        }
    }

    std::cout << "Match nul" << std::endl;
    return 0;
}