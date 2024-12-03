# Morpion - TicTacToe - Alice JACQUES

### Comment exécuter le programme ?
Il faut utiliser **CMake** pour exécuter le programme. 

### Système d'exploitation testé
J'ai testé le programme sur **Windows**.

### Ajout de fonctionnalités 
 
<u>**Amélioration de l'IA** :</u> A ce jour, l'IA est capable de **bloquer les coups de son adversaire.** L'ordinateur joue un coup aléatoire sur une case vide, mais si l'adversaire a 2 symboles alignés, l'ordinateur joue sur la case restante pour bloquer l'adversaire.

<u>**Tentative de création du Gomoku** :</u> J'ai également tenté de créer un **Gomoku**, mais j'ai eu un problème concernant le fait de vérifier sur un tableau de 15/15 si il y avait 5 pions alignés. Comme le projet n'est pas totalement aboutit, je ne vais pas le partager en entier mais voici **diverses pistes **de ce que j'ai pu faire pour le Gomoku :

Comme la grille est beaucoup plus grande que pour le morpion, j'ai décidé de faire un tableau de `char` en deux dimensions d'utiliser les coordonnées x,y plutôt que de faire comme pour le morpion, un tableau de 9 où le joueur doit saisir la case correspondant au numéro de la case (1 à 9 suivant l'emplacement de la case).
- A la place du `void draw_game_board(const char board[9]);` dans le `Plateau.h`, j'ai déclaré `void draw_game_board(const char board[15][15]);`
- Pour la fonction permettant de faire la mécanique d'un tour de jeu, cela donne

```cpp
void your_turn(char board[15][15], Player player)
{
    int x, y;
    std::cout << player.name << ", entrez les coordonnées (x y) : ";
    std::cin >> x >> y;

    while (x < 0 || x >= 15 || y < 0 || y >= 15 || board[y][x] != '.')
    {
        std::cout << "Coordonnées invalides ou case occupée. Réessayez : ";
        std::cin >> x >> y;
    }

    board[y][x] = player.symbol;
}
```

### Points de blocages 
Durant la conception de ce projet, j'ai rencontré quelques difficultés notamment lors de la réalisation de la **partie IA** qui bloque son adrevsaire si il aligne deux symboles verticalement, horizontalement ou diagonalement. Après plusieurs tentatives, j'ai trouvé une solution consistant à faire une boucle parcourtant toutes les cases du tableau. Si une case est vide, l'IA simule un coup de l'adversaire en y plaçant le symbole adverse `opponent_symbol`.
Après avoir simulé le coup de l'adversaire, l'IA appelle la fonction `victory` pour vérifier si ce coup permettrait à l'adversaire de gagner.
- Si oui : Cela signifie que l'adversaire pourrait gagner à cet endroit. L'IA place alors immédiatement son propre symbole (ia.symbol) sur cette case pour bloquer cette victoire et termine son tour (return).
- Sinon : Elle remet la case à son état initial et continue la boucle. Le reste de la boucle permet à l'IA de choisir une case vide random.


### Améliorations possibles

Le jeu du morpion fonctionne mais il serait tout de même possible d'améliorer l'IA en se basant sur un **algorithme de recherches** afin que l'ordinateur envisage plein de possibilités pour jouer le meilleur coup possible de son point de vue. 

Il serait aussi possible d'ajouter une **interface graphique.** J'ai essayé de me renseigner mais comme je ne maitrise pas du tout le sujet et qu'il faut installer des choses, je ne suis pas allée très loin dans cette piste.

Enfin, comme mentionné plus haut, une autre amélioration principale aurait été de faire fonctionner totalement le **Gomoku**.
 
  