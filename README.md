# 🧩 Solveur de Sudoku en C (Backtracking)

Ce projet est un programme développé en **langage C natif** capable de résoudre automatiquement des grilles de Sudoku complexes. Il a été conçu pour mettre en pratique des concepts d'algorithmique avancée, notamment la récursivité et l'optimisation par **retour sur trace (Backtracking)**.

## 🚀 Fonctionnalités
* **Algorithme optimisé :** Utilisation du backtracking pour explorer intelligemment l'arbre des possibilités.
* **Validation mathématique :** Vérification stricte des règles du Sudoku (lignes, colonnes, sous-grilles 3x3).
* **Architecture légère :** Aucun appel à des bibliothèques externes, gestion directe des matrices 2D.

## 🧠 Comment fonctionne l'algorithme ?
L'algorithme parcourt la grille à la recherche de cases vides. Pour chaque case, il tente d'insérer un chiffre de 1 à 9 de manière récursive. Si une impasse est rencontrée (aucun chiffre n'est valide), le programme effectue un *retour sur trace* (backtrack), annule son dernier coup et explore une nouvelle branche de possibilités, garantissant ainsi de trouver la solution exacte si elle existe.

## 🛠️ Compilation et Exécution
Pour compiler et exécuter ce code localement, utilisez le compilateur GCC :

```bash
# Compiler le programme
gcc main.c -o sudoku

# Lancer l'exécutable (Linux/Mac)
./sudoku

# Lancer l'exécutable (Windows)
.\sudoku.exe
