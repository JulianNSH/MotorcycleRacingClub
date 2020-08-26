
#include "ffisier.h"
//functia de creare a unui fisier
int creare(){
	int n;

	printf("**********Crearea fisierului**********\n");
	printf("\nIntroduceti denumirea fisierului>>>");
	scanf("%s", nume);
	
	f=fopen(nume, "w");
	
	if (f==NULL){
		puts("\nFisierul nu a fost creat!");
		return 0;
	}
	completare(0);
	fclose(f);
	printf("\nFisierul a fost creat cu succes!");
	getch();
	
}



//functia completare face parte din functia adaugare
int completare(int i){
	int n, j;
	printf("\nIntroduceti numarul de participanti la cursa>>>");
	scanf("%d", &n);

	for(j=i; j<n+i; j++){

		printf("\nIntroduceti numele participantului #%d>>>", j+1);
		scanf("%s", moto.nume);

		printf("\nIntroduceti prenumele participantului #%d>>>", j+1);
		scanf("%s", moto.prenume);

		printf("\nIntroduceti Data/Luna/Anul nasterii participantului #%d>>>", j+1);
		scanf("%s", moto.data_nasterii);

		printf("\nIntroduceti modelul motocicletei participantului #%d>>>", j+1);
		scanf("%s", moto.model_moto);

		printf("\nIntroduceti numarul de cursa al participantului #%d>>>", j+1);
		scanf("%d", &moto.nr_cursa);

		printf("\nIntroduceti locul ocupat in cursa participantului #%d>>>", j+1);
		scanf("%d", &moto.nr_loc);
		
		fprintf(f, "%d. %s %s %s %s %d %d\n", j+1, moto.nume, moto.prenume, moto.data_nasterii, moto.model_moto, moto.nr_cursa, moto.nr_loc);

	}
	if (f!=NULL){
		puts("\nDatele au fost introduse cu succes!");
		return 1;
	}
	
}




int adaugare(){
	int n, j, i=0;
	char id[10];
	
	printf("**********Adaugare in fisier**********\n");
	printf("\nIntroduceti denumirea fisierului>>>");
	scanf("%s", nume);
//deschiderea fisierului dupa numele introdus
	f=fopen(nume, "r+");
	
	if(f==NULL){
		printf("\nFisier inexistent!!");
		getch();
		return 0;
	}
//parcurgerea fisierului pana la ultimul element
	while(!feof(f)) fgets(id, 100, f);
	fseek(f, 0, SEEK_END);
	completare(id[0]-'0');
	fclose(f);
	getch();
	return 1;
}




//functia pentru afisare a datelor din fisier
int afisare(){
	printf("**********Afisarea datelor**********\n");
	int i;
	

	printf("\nIntroduceti denumirea fisierului: ");
	scanf("%s", nume);
	
	f=fopen(nume, "r");
	if (f==NULL){
		printf("\nFisier inexistent!");
		getch();
		return 0;
	}
	printf("\n******************************Participantii la cursa***********************************");
	printf("\n_______________________________________________________________________________________\n");
	printf("|Nr|    Nume/Prenume   |DD/LL/AA nasterii|Modelul Motocicletei|Nr de cursa|Nr de finis|\n");
	printf("---------------------------------------------------------------------------------------\n");
	while(fscanf(f, "%d. %s %s %s %s %d %d", &i, &moto.nume, &moto.prenume, &moto.data_nasterii, &moto.model_moto, &moto.nr_cursa, &moto.nr_loc)!=EOF){
		printf("|%2d|%9s %9s|%17s|%20s|%11d|%11d|\n", i, &moto.nume, &moto.prenume, &moto.data_nasterii, &moto.model_moto, moto.nr_cursa, moto.nr_loc);
	}
		printf("---------------------------------------------------------------------------------------\n");
	fclose(f);
	getch();
	return 1;
}



//Divizarea fisierului principal in 2 secunde dupa numarul de cursa a participantilor (par/impar)
int divizare(){
		printf("**********Divizarea in 2**********\n");
//	char nume1[20], nume2[20];
	int i, var;
	printf("\nIntroduceti denumirea fisierului: ");
	scanf("%s", nume);
	
	afisare();

	f=fopen(nume, "r");
	if (f==NULL){
		printf("\nFisier inexistent!");
		getch();
		return 0;
	}
	printf("\n***Fisierul introdus va fi divizat in 2 fisiere secundare***");
	printf("\nIntroduceti numele primului fisier: ");
	scanf("%s", nume1);
	printf("\nIntroduceti numele fisierului doi: ");
	scanf("%s", nume2);
	
	FILE *f1, *f2;
	f1 = fopen(nume1, "w");
	f2 = fopen(nume2, "w");
	
//repartizarea dupa principiul par/impar
	while(fscanf(f, "%d. %s %s %s %s %d %d", &i, &moto.nume, &moto.prenume, &moto.data_nasterii, &moto.model_moto, &moto.nr_cursa, &moto.nr_loc)!=EOF){
		if(moto.nr_cursa %2 == 0){
			fprintf(f1, "%d. %s %s %s %s %d %d\n", i, moto.nume, moto.prenume, moto.data_nasterii, moto.model_moto, moto.nr_cursa, moto.nr_loc);
		} else {
			fprintf(f2, "%d. %s %s %s %s %d %d\n", i, moto.nume, moto.prenume, moto.data_nasterii, moto.model_moto, moto.nr_cursa, moto.nr_loc);	
		}
	}
	if(f1!=NULL&&f2!=NULL){
		printf("\nFisierele au fost create cu success");
	}
	
	fclose(f1); fclose(f2);
	
	v2: printf("\nDoriti sa vizualizati fisierele? [1.DA/2.NU]>>>");
	scanf("%d", &var);
	printf("\n");
	
	switch (var){
		case 1: afisare(); afisare(); break;
		case 2: break;
		default: ("\nAti introdus o varianta inadmisibila"); goto v2; break;
	}

	getch();
	return 1;
	
}



//Modificarea datelor din fisier
int modificare(){
		printf("**********Modificarea fisierului**********\n");
		int i, nr;
		int n =0;

		FILE * temp;
		temp=fopen("temp.txt", "w");
	

	printf("\nIntroduceti denumirea fisierului: ");
	scanf("%s", nume);
	
	afisare();
	
	f=fopen(nume, "r");


	if (f==NULL){
		printf("\nFisier inexistent!");
		getch();
		return 0;
	}
	
	printf("\nIntroduceti numarul de ordine a participantului care necesita a fi modificat: ");
	scanf("%d", &nr);
//introducerea datelor pentru modificare in structura
	

	while(fscanf(f, "%d. %s %s %s %s %d %d", &i, &moto.nume, &moto.prenume, &moto.data_nasterii, &moto.model_moto, &moto.nr_cursa, &moto.nr_loc)!=EOF){

			fprintf(temp, "%d. %s %s %s %s %d %d\n", i, moto.nume, moto.prenume, moto.data_nasterii, moto.model_moto, moto.nr_cursa, moto.nr_loc); 	

	}
	
	fclose(f); fclose(temp);

		temp=fopen("temp.txt", "r");
		f=fopen(nume, "w");

	while(fscanf(temp, "%d. %s %s %s %s %d %d", &i, &moto.nume, &moto.prenume, &moto.data_nasterii, &moto.model_moto, &moto.nr_cursa, &moto.nr_loc)!=EOF){
		
	  if(nr==i){
	
		printf("\nIntroduceti numele nou al participantului #%d>>>", nr);
		scanf("%s", moto.nume);

		printf("\nIntroduceti prenumele nou al participantului #%d>>>", nr);
		scanf("%s", moto.prenume);

		printf("\nIntroduceti Data/Luna/Anul nasterii nou al participantului #%d>>>", nr);
		scanf("%s", moto.data_nasterii);

		printf("\nIntroduceti modelul nou al  motocicletei participantului #%d>>>", nr);
		scanf("%s", moto.model_moto);

		printf("\nIntroduceti numarul de cursa nou al participantului #%d>>>", nr);
		scanf("%d", &moto.nr_cursa);

		printf("\nIntroduceti locul nou ocupat in cursa participantului #%d>>>", nr);
		scanf("%d", &moto.nr_loc);
		}
		
		fprintf(f, "%d. %s %s %s %s %d %d\n", i, moto.nume, moto.prenume, moto.data_nasterii, moto.model_moto, moto.nr_cursa, moto.nr_loc); 
	}
		fclose(f); fclose(temp);
		
	printf("\nFisierul a fost modificat cu success\n");
	
	afisare();
		getch();
	return 1;
}


//afisarea selectiva a fisierului
int afis_selec(){
		printf("**********Afisarea selectiva**********\n");
		int i=1;
	printf("\nIntroduceti denumirea fisierului: ");
	scanf("%s", nume);

	f=fopen(nume, "r");
	if (f==NULL){
		printf("\nFisier inexistent!");
		getch();
		return 0;
	}
		
as: printf("____________________________\n");
	printf("|    Afisarea Selectiva    |\n");
	printf("----------------------------\n");
	printf("| 1.Primul finalist        |\n");
	printf("| 2.Primii trei finalisti  |\n");
	printf("| 3.Primii cinci finalisti |\n");
	printf("| 4.Primii zece finalisti  |\n");
	printf("| 0.        Iesire         |\n");
	printf("----------------------------\n");
	
	 int nr;
	 fseek(f, 0, SEEK_SET);
	printf("Alegeti una din optiunile propuse>>>");
	scanf("%d", &nr);
//Transformarea variantei alese in valoarea indicata in conditie
	switch(nr){
		case 1:        break;
		case 2: nr=3;  break;
		case 3: nr=5;  break;
		case 4: nr=10; break;
		case 0: fclose(f); return 1; break;
		default: printf("\nAti introdus o varianta inadmisibila!"); goto as; break;
	}
	
	printf("\n_______________________________________________________________________________________\n");
	printf("|Nr|    Nume/Prenume   |DD/LL/AA nasterii|Modelul Motocicletei|Nr de cursa|Nr de finis|\n");
	printf("---------------------------------------------------------------------------------------\n");
//Afisarea selectiva	
	while(fscanf(f, "%d. %s %s %s %s %d %d", &i, &moto.nume, &moto.prenume, &moto.data_nasterii, &moto.model_moto, &moto.nr_cursa, &moto.nr_loc)!=EOF){
		if(moto.nr_loc<=nr){
			printf("|%2d|%9s %9s|%17s|%20s|%11d|%11d|\n", i, &moto.nume, &moto.prenume, &moto.data_nasterii, &moto.model_moto, moto.nr_cursa, moto.nr_loc);
		//	i++;
		}
	}
	printf("---------------------------------------------------------------------------------------\n"); goto as;
	fclose(f);
	getch();
	return 1;
}




//sortarea fisierului introdus
int sortare(){
		printf("**********Sortarea fisierului**********\n");
	int id, n=0;
	int temp, i;
	struct motociclisti moto2[100];
	printf("\nIntroduceti denumirea fisierului: ");
	scanf("%s", nume);

	f=fopen(nume, "r+");
	if (f==NULL){
		printf("\nFisier inexistent!");
		getch();
		return 0;
	}
	
	while(fscanf(f, "%d. %s %s %s %s %d %d\n", &id, &moto2[n].nume, &moto2[n].prenume, &moto2[n].data_nasterii, &moto2[n].model_moto, &moto2[n].nr_cursa, &moto2[n].nr_loc)!=EOF) n++;
//algoritmul SHELL
	for(temp=n/2; temp>0; temp/=2){
		for (i=temp; i<n; i++){
			moto = moto2[i];
			
			int j;
			for(j = i; j>=temp&&moto2[j-temp].nr_loc>moto.nr_loc; j-=temp)
				moto2[j] = moto2[j-temp];
				
			moto2[j] = moto;
		}
	}
//Inscrierea in fisier
	fseek(f, 0, SEEK_SET);
	for(i=0; i<n; i++)
		fprintf(f, "%d. %s %s %s %s %d %d\n", i+1, &moto2[i].nume, &moto2[i].prenume, &moto2[i].data_nasterii, &moto2[i].model_moto, moto2[i].nr_cursa, moto2[i].nr_loc);
	fclose(f);
	printf("\nFisierul a fost sortat cu success!");
	getch();
	return 1;
}



