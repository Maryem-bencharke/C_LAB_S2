#ifndef header_h
#define header_h

#include<stdio.h>
#include<stdlib.h>

struct cellule
{
    char element;
    struct cellule *suivant;
};
typedef struct cellule cellule;
typedef cellule *liste;

int testVide(liste);
unsigned longueur(liste);
void affichageListe(liste);
void ajoutDebut(int,liste *);
void ajoutFin(int,liste *);
void suppressionDebut(liste *);
void suppressionFin(liste *);
void liberer(liste);
liste recherche(int, liste);
unsigned occurence(int,liste);
unsigned length(liste);
#endif