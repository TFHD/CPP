# Explications rapide pour l'exo 2 du CPP module 09

# 🧠 Algorithme de Ford-Johnson (Merge-Insertion Sort) en C++

## 📌 Sommaire
1. [Introduction](#introduction)
2. [Principe de l’algorithme](#principe-de-lalgorithme)
3. [Étapes détaillées](#étapes-détaillées)
4. [Complexité](#complexité)
5. [Exemple d'exécution](#exemple-dexécution)

---

## 📘 Introduction

L’algorithme de Ford-Johnson, ou Merge-Insertion Sort, est un tri par comparaison conçu pour minimiser le nombre de comparaisons. Bien qu’il soit rarement utilisé dans les applications pratiques à cause de sa complexité, il reste un algorithme fascinant dans l’étude théorique de l’algorithmie. Pour cette explication de l'algorithme je vous recommande d'aller lire celle de emuminov (https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91) en tout cas je me base sur ses recherches pour ce ReadMe.

---

## ⚙️ Principe de l’algorithme

- Les éléments sont d’abord regroupés en paires.
- Chaque paire est triée.
- Les éléments les plus grands de chaque paire sont triés récursivement.
- Les plus petits sont insérés un à un dans la liste triée selon une stratégie spécifique (souvent avec recherche binaire optimisée).

---

## 🔍 Étapes détaillées

1. Former des paires d’éléments.
2. Trier chaque paire localement.
3. Créer une sous-liste avec les éléments les plus grands.
4. Trier récursivement cette sous-liste.
5. Insérer les éléments restants dans l’ordre correct.

---

## ⏱️ Complexité

- Nombre de comparaisons : environ **n log₂ n − 1.44n**
- Complexité en temps : **O(n log n)** en moyenne.
- Moins utilisé en pratique que le tri rapide ou le tri fusion.

---

## 🧾 Exemple d'exécution

```text
Entrée : [7, 3, 5, 2, 9, 1, 4 ,2]

Etape 1, Trier recursivement les paires : On trie ici grace au dernier element de la paire (car c'est la plus grande)

  Recursion niv 1 : ----> Taille d'une paire : 1, soit 8 paires de 1
    Paires : (7,3),(5,2),(9,1),(4,2)
    Triées localement : (3,7),(2,5),(1,9),(2,4)
  
  Recursion niv 2 : ----> Taille d'une paire : 2, soit 4 paires de 2
    Paires : ([3,7],[2,5]),([1,9],[2,4])
    Triées localement : ([2,5],[3,7]),([2,4],[1,9])
  
  Recursion niv 3 : ----> Taille d'une paire : 4, soit 2 paires de 4 
    Paires : ([2,5,3,7],[2,4,1,9])
    Triées localement : [2,5,3,7],[2,4,1,9] #Rien ne change car 7 < 9
  
  Recursion niv 4 : ----> Taille d'une paire : 8, soit 1 paires de 8 /!\ On ne peut plus former 2 paires /!\

          FIN de l'etape de recursion pour le tri de paires

Etape 2, Trier en inserant les paires : On reprend sur la taille max de paire qu'on a pu faire, et on va etiquetté ces paires (b1, a1, b2, a2, b3, a3 ....)
                                        Il faut savoir aussi que toutes les paires b2 -> b(n) vont dans PEND et b1, a1 -> a(n) va dans MAIN.
                                        On insère les paires en fonction du dernier élément de la paire (toujours).
                                        On peut passer à l'etape suivante de la recursion si le PEND est vide.

  Recursion niv 3 :
  La liste actuelle : [2,5,3,7],[2,4,1,9]
                       b1        a1
                PEND
    /---------------------------\
    |                           |
    |                           |
    \---------------------------/

                MAIN
    /---------------------------\
    | [2,5,3,7],[2,4,1,9]       |
    |  b1        a1             |
    \---------------------------/

  Recursion niv 2 :
  Dans cette étape vu qu'on va insérer des paires, il faut que vous sachiez comment on les insère, vous avez 2 choix possibles :
  Soit vous utiliser la recherche binaire pour inserer les paires.
  Soit vous utiliser la suite de JacobShtal (elle permet de faire moins de comparaisons, ce qui va de paire avec cet algorithme :) )
  Pour JacobShtal je vous laisse vous documenter pour comprendre la suite.
  Pour expliquer rapidement comment ça fonctionne, on commence au chiffre 3 (indice 3) de la suite, ce chiffre va définir quelle etiquette du PEND b(jacobShtal_number) on va inserer.
  Donc on commencera à inserer b3 (puis on dessens) et b2, on tire maintenant le chiffre de la suite de JacobShtal a l'indice (n + 1) donc on aura 5 puis 11.... .
  On change de chiffre d'indice n de la suite de JacobSthal tout les U(n) - U(n - 1), exemple U(3) - (2) = 3 - 1 = 2, donc on doit faire 2 insertions
  U(4) - (3) = 5 - 3 = 2, donc on doit faire 2 insertions
  U(5) - (4) = 11 - 5 = 6, donc on doit faire 6 insertions
  ...
  
  
  La liste actuelle : [2,5],[3,7],[2,4],[1,9]
                       b1    a1    b2    a2
                PEND                                          PEND
    /---------------------------\    On insere    /---------------------------\
    | [2,4]                     |      [2,4]      |                           |
    |  b2                       |     Dans le     |                           |
    \---------------------------/      Main       \---------------------------/

                MAIN                                         MAIN
    /---------------------------\                 /---------------------------\
    | [2,5],[3,7],[1,9]         |                 | [2,4],[2,5],[3,7],[1,9]   |
    |  b1    a1    a2           |                 |  b2    b1    a1    a2     |
    \---------------------------/                 \---------------------------/

  Recursion niv 1 :
  La liste actuelle : [2], [4], [2], [5], [3], [7], [1], [9]
                      b1   a1   b2   a2   b3   a3   b4   a4


        Chiffre de Jacob : 3                          Chiffre de Jacob : 3                          Chiffre de Jacob : 5
                PEND                                          PEND                                          PEND                                          PEND
    /---------------------------\    On insere    /---------------------------\    On insere    /---------------------------\      On insere     /---------------------------\
    | [2],[3],[1]               |       [3]       | [2],[1]                   |       [2]       | [1]                       |         [1]        |                           |
    | b2  b3  b4                |     Dans le     | b2  b4                    |     Dans le     | b4                        |       Dans le      |                           |
    \---------------------------/      Main       \---------------------------/      Main       \---------------------------/        Main        \---------------------------/

                MAIN                                         MAIN                                              MAIN                                         MAIN
    /---------------------------\                 /---------------------------\                 /------------------------------\                 /----------------------------------\
    | [2],[4],[5],[7],[9]       |                 | [2],[3],[4],[5],[7],[9]   |                 | [2],[2],[3],[4],[5],[7],[9]  |                 | [1],[2],[2],[3],[4],[5],[7],[9]  |
    | b1  a1  a2  a3  a4        |                 | b1  b3  a1  a2  a3  a4    |                 | b1  b2  b3  a1  a2  a3  a4   |                 | b4  b1  b2  b3  a1  a2  a3  a4   |
    \---------------------------/                 \---------------------------/                 \------------------------------/                 \----------------------------------/

Voici la liste maintenant triée : 1,2,2,3,4,5,7,9
```

Voici un court exemple de comment appliquer l'algorithme de Ford jonhson, je vous recommande encore de suivre le tutoriel de emuminov qui explique plus en détails l'algorithme.
(https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91)
