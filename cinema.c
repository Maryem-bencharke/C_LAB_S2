#include<stdio.h>
#include<stdlib.h>
typedef struct cellule
{
    int numero;
    int nombre;
    struct cellule *suivant;
}cellule;
 
typedef struct file
{
    cellule *debut;
    cellule *fin;
} file;

void ajout(int numero , file *F)
{
    cellule *D = (cellule *)malloc(sizeof(cellule));
    file temp = *F;
    D->nombre = 0;
    D->numero = numero;
    D->suivant = NULL;
    if((*F).debut == NULL)
    {
        (*F).debut = D;
        (*F).fin = D;
        return;
    }
    while(temp.debut != NULL)
    {
        if((temp.debut->numero) == numero )
        {
            temp.debut->numero ++;
            return;
        }
        temp.debut = temp.debut->suivant;
    }
    (*F).fin->suivant = D;
    (*F).fin = D;
}

void affichage(file F)
{
    file temp = F;
	if(F.debut == NULL)
	{
		printf("[]\n");
		return ;
	}
	printf("[");
	while(temp.debut->suivant != NULL)
	{
		printf("(%d , %d) ,", temp.debut->numero, temp.debut->nombre);
		temp.debut = temp.debut->suivant;
	}
	printf("(%d , %d)]\n", temp.debut->numero, temp.debut->nombre);
}

void retirer(file *F)
{
    cellule * temp = (*F).debut->suivant ;
    (*F).debut = (*F).debut->suivant;
    free(temp);

}
int main()
{
    file F= {NULL,NULL};
    ajout(8,&F);
    ajout(9,&F);
    affichage(F);
    retirer(&F);
    affichage(F);
    return 0;
}
