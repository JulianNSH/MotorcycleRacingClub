#include <stdio.h>
#include <stdlib.h>

//bibliotecile individuale
#include "ffisier.h"
#include "fliste.h"


int fisier(){

	int c;
	BACK:	system("cls");
	printf("______________________________\n");
	printf("|        MENIU FISIERE       |\n");
	printf("------------------------------\n");
	printf("|**Alegeti una din variante**|\n");
	printf("------------------------------\n");
	printf("| 1.  Crearea unui fisier    |\n");
	printf("------------------------------\n");
	printf("| 2.  Adaugarea in fisier    |\n");
	printf("------------------------------\n");
	printf("| 3.  Afisarea fisierelor    |\n");
	printf("------------------------------\n");
	printf("| 4. Divizarea in 2 fisiere  |\n");
	printf("------------------------------\n");
	printf("| 5. Modificarea fisierelor  |\n");
	printf("------------------------------\n");
	printf("| 6.   Afisarea selectiva    |\n");
	printf("------------------------------\n");
	printf("| 7.    Sortarea datelor     |\n");
	printf("------------------------------\n");
	printf("| 0.         Iesire          |\n");
	printf("------------------------------\n");

	
    printf("\nIntroduceti varianta aleasa>>>");
    
    scanf("%d", &c);
    
        switch(c){
    	case 1 : system("cls"); creare();    goto BACK; break;
    	case 2 : system("cls"); adaugare();  goto BACK; break;
    	case 3 : system("cls"); afisare();   goto BACK; break;
    	case 4 : system("cls"); divizare();  goto BACK; break; 
    	case 5 : system("cls"); modificare();goto BACK; break;
    	case 6 : system("cls"); afis_selec();goto BACK; break;
    	case 7 : system("cls"); sortare();   goto BACK; break;
    	case 0 : return 1;  break;
    	default: printf("!!!Ati introdus o varianta inexistenta!!!");break;
	}

}
//Meniul listelor
int liste(){
	    int c;
	BACK:    system("cls");
	printf("______________________________\n");
	printf("|         MENIU LISTE        |\n");
	printf("------------------------------\n");
	printf("|**Alegeti una din variante**|\n");
	printf("------------------------------\n");
	printf("| 1.   Crearea unei liste    |\n");
	printf("------------------------------\n");
	printf("| 2.     Afisarea listei     |\n");
	printf("------------------------------\n");
	printf("| 3.Inserarea a doua elemente|\n");
	printf("------------------------------\n");
	printf("| 4.Stergerea a doua elemente|\n");
	printf("------------------------------\n");
	printf("| 0.         Iesire          |\n");
	printf("------------------------------\n");
	 
    printf("\nIntroduceti varianta aleasa>>>");
    
    scanf("%d", &c);
        switch(c){
    	case 1 : system("cls"); crearelist(); goto BACK; break;
    	case 2 : system("cls"); afislist();   goto BACK; break;
    	case 3 : system("cls"); inserare();   goto BACK; break;
    	case 4 : system("cls"); stergere();   goto BACK; break;
    	case 0 : return 1; break;
    	default: printf("!!!Ati introdus o varianta inexistenta!!!");break;
	}

}

void main() {

    int c;
    meniu: system("cls");
	printf("______________________________\n");
	printf("|            MENIU           |\n");
	printf("------------------------------\n");
	printf("|**Alegeti una din variante**|\n");
	printf("------------------------------\n");
	printf("|  1. Lucrul cu fisierele    |\n");
	printf("------------------------------\n");
	printf("|  2.  Lucrul cu listele     |\n");
	printf("------------------------------\n");
	printf("|  0.        Iesire          |\n");
	printf("------------------------------\n");
	 
    printf("\nIntroduceti varianta aleasa>>>");
    
    scanf("%d", &c);
    
    switch(c){
    	case 1 : fisier();goto meniu; break;
    	case 2 : liste(); goto meniu;  break;
    	case 0 : exit(1); goto meniu; break;
    	default: printf("!!!Ati introdus o varianta inexistenta!!!");break;
	}

}
