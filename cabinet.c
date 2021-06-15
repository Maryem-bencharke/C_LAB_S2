#include<stdio.h>
#include<stdlib.h>
typedef struct patient
{
	char nom[10];
	char prenom[10];
	int rdv;
} patient;

typedef struct cellule
{
	patient patient;
	struct cellule * suivant;
} cellule;

typedef struct cellule * liste;

void ajout_patient(patient P , liste *L)
{
    liste temp = *L;
    cellule *C =(cellule *)malloc(sizeof(cellule));
    C->patient = P;
    if (L == NULL)
    {
        *L = C;
        C->suivant = NULL;
        return;
    }
    else
    {
        if(P.rdv == 0)
        {
            while(temp != NULL)
            {
                temp = temp->suivant;
            }
            C->suivant = NULL;
            temp->suivant = C;
            return;
        }
        if(P.rdv == 1)
        {
            if(temp->patient.rdv == 0)
		    {
			    C->suivant = *L;
			    *L = C;
			    return ;
		    }
		    while(temp->suivant != NULL && temp->suivant->patient.rdv != 0)
		    {
			    temp = temp->suivant;
	    	}
		    C->suivant = temp->suivant;
		    temp->suivant = C;
		    return ;
        }
        return;

    }
}

void extraire_patient(patient P , liste *L)
{
    liste temp = *L;
    *L = (*L)->suivant;
    free(temp);
    return;
}

