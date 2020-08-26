#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#ifndef FFISIER_H_
#define FFISIER_H_
//structura
struct motociclisti{
	char nume[20];
	char prenume[20];
	char data_nasterii[11];
	char model_moto[20];
	int  nr_cursa;
	int  nr_loc;
}moto;

//variabile
	char nume[20];
//fisier
	FILE *f; 

//functii
int creare();
int adaugare();
int afisare();
int divizare();
int modificare();
int afis_selec();
int sortare();


#endif 
