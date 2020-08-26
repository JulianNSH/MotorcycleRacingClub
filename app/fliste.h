#include <stdio.h>
#include <stdlib.h>
//importam biblioteca individuala pentru a utiliza structura creata


#ifndef FLISTE_H_
#define FLISTE_H_
//structura
#include "ffisier.h"
//liste
typedef struct lista{

	struct motociclisti moto;
	struct lista *next;
}nod;

nod *prim,*q;

//Variabile
char numelist[20];

//Functiile
int crearelist();
int afislist();
int inserare();
int stergere();

#endif
