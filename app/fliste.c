#include "fliste.h"

//Functia pentru creare a listei
int crearelist(){
	int i = 1; int nr;
	printf("\nIntroduceti denumirea listei: ");
	scanf("%s", &numelist);
	
	printf("\nIntroduceti numarul de elemente care doriti sa-l introduceti in lista>>> ");
	scanf("%d", &nr);
	for(i=1;i<=nr;i++){
				nod *p =(nod*)malloc(sizeof(nod));
		printf("\nIntroduceti numele participantului #%d>>>", i);
		scanf("%s", &p->moto.nume);
		
		printf("\nIntroduceti prenumele participantului #%d>>>", i);
		scanf("%s", &p->moto.prenume);

		printf("\nIntroduceti Data/Luna/Anul nasterii participantului #%d>>>", i);
		scanf("%s", &p->moto.data_nasterii);

		printf("\nIntroduceti modelul motocicletei participantului #%d>>>", i);
		scanf("%s", &p->moto.model_moto);

		printf("\nIntroduceti numarul de cursa al participantului #%d>>>", i);
		scanf("%d", &p->moto.nr_cursa);

		printf("\nIntroduceti locul ocupat in cursa participantului #%d>>>", i);
		scanf("%d", &p->moto.nr_loc);
		p->next=NULL;
		if(prim==NULL){
			prim=p;
		} else {
			q=prim;
			while(q->next!=NULL)q=q->next;
			q->next=p;
			
		}
	}
	printf("\nLista a fost creata cu success!");
	getch();
	return 1;

}

//Functia pentru afisare a listei
int afislist(){
	int i =1;
//	lista *q;
	q=prim;
	printf("\nLista afisata: '%s'", &numelist);


	if(q==NULL){
		printf("\nLista inexistenta!"); getch(); return 1;
	}
	printf("\n_______________________________________________________________________________________\n");
	printf("|Nr|    Nume/Prenume   |DD/LL/AA nasterii|Modelul Motocicletei|Nr de cursa|Nr de finis|\n");
	printf("---------------------------------------------------------------------------------------\n");
	
	while(q!=NULL){
			printf("|%2d|%9s %9s|%17s|%20s|%11d|%11d|\n", i, &q->moto.nume, &q->moto.prenume, &q->moto.data_nasterii, &q->moto.model_moto, q->moto.nr_cursa, q->moto.nr_loc);
		i++;
		q=q->next;
	}
	printf("---------------------------------------------------------------------------------------\n");
	getch();
	return 1;
}
//Functia de inserare a 2 elemente in lista
int inserare(){
	int i, n, nr = 1;
	nod *q, *sec;
	q=prim;
	
	 afislist();
	 
	printf("\nIntroduceti numarul de ordine pentru inserare>>> ");
	scanf("%d", &nr); n=nr+1; nr--; 
	
	for(i=0; i<nr; i++)q=q->next; 
	
	for(i=1; i<=2; i++){
		
		nod *p=(nod*)malloc(sizeof(nod));
		printf("\nIntroduceti numele participantului #%d>>>", n);
		scanf("%s", &p->moto.nume);
		
		printf("\nIntroduceti prenumele participantului #%d>>>", n);
		scanf("%s", &p->moto.prenume);

		printf("\nIntroduceti Data/Luna/Anul nasterii participantului #%d>>>", n);
		scanf("%s", &p->moto.data_nasterii);

		printf("\nIntroduceti modelul motocicletei participantului #%d>>>", n);
		scanf("%s", &p->moto.model_moto);

		printf("\nIntroduceti numarul de cursa al participantului #%d>>>", n);
		scanf("%d", &p->moto.nr_cursa);

		printf("\nIntroduceti locul ocupat in cursa participantului #%d>>>", n);
		scanf("%d", &p->moto.nr_loc);
		
		p->next=NULL;
		q=prim;
		
		if(nr==0){
			q=prim->next;
			prim->next=p;
			p->next=q;
			
		} else {
			sec=q->next;
			q->next=p;
			p->next=sec;	
		}
	n++;	
	}
	 printf("\n******Lista modificata*****\n");
	 afislist();
}

//Functia de stergere a 2 elemente
int stergere(){
		int i, nr = 1;
	nod *q, *sec, *p;
	q=prim;
	 afislist();
	 
	printf("\nIntroduceti numarul de ordine pentru stergerea a 2 elemente>>> ");
	scanf("%d", &nr); nr--;
	
	for(i=0; i<nr; i++)q=q->next;
	
	if(nr==0)
	{
		sec=prim->next;
		prim=prim->next->next;
		free(q);free(sec);
	}
	else
	{
	sec=q->next;
	p=q->next->next;
	q->next=q->next->next->next;
	free(sec);free(p);
	}
	
	printf("\n******Lista modificata*****\n");
	afislist();
	
}

