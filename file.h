#ifndef file_H
#define file_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

struct cellule_double
{
    int element;
    struct cellule_double * suivant;
    struct cellule_double * precedent;
};
typedef struct cellule_double cellule_double;

struct file
{
    cellule_double * debut;
    cellule_double * fin;
};
typedef struct file file;

int fileVide(file);
int lire(file);
void enfiler(int,file *);
int defiler(file *);
void liberer(file);
void affichage_file(file);
#endif
