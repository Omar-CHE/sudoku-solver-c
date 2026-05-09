#include <stdio.h>
#include <stdbool.h>

#define N 9

// Affichage de la grille
void afficher_grille(int grille[N][N]) {
    for (int l = 0; l < N; l++) {
        for (int c = 0; c < N; c++) {
            printf("%2d", grille[l][c]);
        }
        printf("\n");
    }
}

// Verifie si on peut placer 'valeur' aux coordonnees (l, c)
bool est_valide(int grille[N][N], int l, int c, int valeur) {
    
    // Verif ligne et colonne
    for (int x = 0; x < N; x++) {
        if (grille[l][x] == valeur) return false;
        if (grille[x][c] == valeur) return false;
    }

    // Verif du bloc 3x3
    int debut_ligne = l - (l % 3); 
    int debut_colonne = c - (c % 3); 

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grille[i + debut_ligne][j + debut_colonne] == valeur) {
                return false;
            }
        }
    }

    return true; 
}

// Fonction recursive de resolution par backtracking
bool resoudre_sudoku(int grille[N][N]) {
    int l, c;
    bool case_vide = false;

    // Recherche d'une case vide (0)
    for (l = 0; l < N; l++) {
        for (c = 0; c < N; c++) {
            if (grille[l][c] == 0) {
                case_vide = true;
                break;
            }
        }
        if (case_vide) break;
    }

    // Fin : plus de cases vides, le sudoku est resolu
    if (!case_vide) return true; 

    // Test des chiffres de 1 a 9
    for (int val = 1; val <= 9; val++) {
        
        if (est_valide(grille, l, c, val)) {
            grille[l][c] = val; // On tente la valeur

            // Appel recursif
            if (resoudre_sudoku(grille)) {
                return true; 
            }

            // Echec : on annule (backtrack) et on testera la valeur suivante
            grille[l][c] = 0;
        }
    }

    return false;
}

int main() {
    int grille[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    printf("--- Grille de depart ---\n");
    afficher_grille(grille);

    if (resoudre_sudoku(grille)) {
        printf("\n--- Sudoku resolu ---\n");
        afficher_grille(grille);
    } else {
        printf("\nAucune solution trouvee.\n");
    }

    return 0;
}