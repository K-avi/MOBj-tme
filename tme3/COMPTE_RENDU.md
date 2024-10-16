# TME 3 de MOBJ de Laila LAHKIM BENNANI (21102544) et Ivan MULOT-RADOJCIC (21102722)

## Question 1

cf question.cpp et main.cpp

## Question 2

Sur la machine où le programme a été testé, backInsert() a pris ~0.10sec, alors que frontInsert() a pris
~1.00sec. Cela est dû au fait que l'insertion en tête dans un vecteur soit en O(n) car il faut décaller
l'ensemble des élements du vecteur. La complexité de backInsert() est donc de O(n²+nlog(n)). Où n est le
nombre de mot que l'on insère. Le nlog(n) est dû au fait que l'on trie le vecteur à la fin de l'execution.
Pour insérer les élements, nous avons simplement appelé la méthode insert()
de la classe std::vector, avec comme premier argument vector\_front.begin().  

## Question 3

Sur la machine où le programme a été testé, sortEachInsert() a pris ~4.40sec. Le temps est dû au fait
que le tri d'un tableau soit en complexité de O(nlog(n)), étant donné que l'on trie le tableau à chaque
insertion, la complexité totale de sortEachInsert() est donc de O(n²log(n)). Où n est le nombres
de mots que l'on insère.

## Question 4

Sur la machine où le programme a été testé, backInsert() a pris ~0.50sec pour la liste.
L'insertion en queue d'une liste doublement chaînée est en complexité O(1), la complexité
de backInsert() est donc en O(n) où n est le nombre de mots à insérer.  

Sur la machine où le programme a été testé, frontInsert() a pris ~0.50sec pour la liste.
L'insertion en tête d'une liste doublement chaînée est en complexité O(1), la complexité
de frontInsert() est donc en O(n+nlog(n)) où n est le nombre de mots à insérer.

Sur la machine où le programme a été testé, sortEachInsert() a pris ~1.80sec pour la liste.
L'insertion en tête d'une liste doublement chaînée est en complexité O(1), la complexité
de sortEachInsert() est donc en O(n²log(n)) où n est le nombre de mots à insérer.

## Question 5

cf questions.cpp et main.cpp

## Question 6

On voit que l'utilisation de la fonction de tri rend l'execution de la fonction d'insertion dans la map
significativement plus rapide.
