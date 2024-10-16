
#ifndef  C_BOX_H
#define  C_BOX_H // il ne faut pas donner de valeur à la macro 

// ajout des librairies pour les FILE et size_t
#include <stdlib.h>
#include <stdio.h>


typedef struct Box_s {
    char* name_;
    long  x1_;
    long  y1_;
    long  x2_;
    long  y2_;
}Box; // ajout du point virgule après la définition de la structure, 
// et ajout du typedef pour pouvoir utiliser Box comme un type dès la définition de la structure

// ajout de l'argument void par bonne pratique
size_t  boxAllocateds   (void); 
Box*    boxCreateEmpty  (void);

Box*    boxCreate       ( const char* name, long x1, long y1, long x2, long y2 );
Box*    boxCreateCopy   ( const Box* other );
void    boxDelete       ( Box* box ); // ajout du point virgule après la définition de la fonction
long    boxIsEmpty      ( const Box* box );
long    boxGetWidth     ( const Box* box ); 
long    boxGetHeight    ( const Box* box ); // ajout du point virgule après la définition de la fonction
long    boxIntersect    ( const Box* box1, const Box* box2 );
Box*    boxIntersection ( const Box* box1, const Box* box2 );
Box*    boxInflate      ( Box* box, long dx1, long dy1, long dx2, long dy2 );
void    boxPrint        ( FILE* o, Box* box );


#endif  // C_BOX_H
