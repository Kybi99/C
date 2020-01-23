/*Dragan Kuburovic RT-36/18*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/*Struktura podataka u kojoj se nalaze polja iz asocijacije*/

struct polja{
	char A1[21], A2[21], A3[21], B1[21], B2[21], B3[21], C1[21], C2[21], C3[21], D1[21], D2[21], D3[21], D[21], A[21], B[21], C[21], Konacno[21];
};

void ispis(char A1[21],char A2[21],char A3[21],char B1[21],char B2[21],char B3[21],char C1[21],char C2[21],char C3[21],char D1[21],char D2[21],char D3[21],char A[21],char B[21],char C[21],char D[21],char Konacno[21]);


/*Glavna funkcija koja sadrzi dinamicku dodelu memorije , tekstualnu datoteku, i igru asocijacije*/

main() {
	struct polja *niz;
	char s[21],odgovor1[21];
	int i,j,n=1,m,brojac=0,k,rezultat=42,flag=0,brojac2=0;
	char A1[21]="A1", A2[21]="A2", A3[21]="A3", B1[21]="B1", B2[21]="B2", B3[21]="B3", C1[21]="C1", C2[21]="C2", C3[21]="C3", D1[21]="D1", D2[21]="D2", D3[21]="D3", D[21]="D", A[21]="A", B[21]="B", C[21]="C", Konacno[21] = "Konacno";
	FILE *fptr1;

	/*Dinamicka dodela memorije*/

	niz = (struct polja*) malloc(n * sizeof(struct polja));
	if (niz == NULL) {
		printf("Neuspesna dodela memorije");
		exit(1);
	}

	/*Odabir asocijacije*/

	printf("Unesite broj od 1 do 3 da odaberete asocijaciju\n");
	scanf("%d",&m);

	/*ispis praznih polja*/
	ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C,D, Konacno);

	printf("Napomena...\n");
	printf("Ako pogresite pet puta izgubili ste!\n\n");
	printf("Mozete pogledati resenje u tekstualnoj datoteci\n\n");
	printf("Pravila");
	printf("\nUnesite polje koje zelite da otvorite(A1,A2,A3,B1,B2,B3...)\n");
	printf("Ukoliko zelite da date odgovor za kolonu ili konacno unestite za kolonu npr.('A') , a za konacno ('konacno')\n");

	/*Ubacivanje teksta u polja iz strukture*/

	if(m==1){
		strcpy(niz[0].A1, "svetlo");
		strcpy(niz[0].A2, "vostana");
		strcpy(niz[0].A3, "fitilj");
		strcpy(niz[0].A,"sveca");

		strcpy(niz[0].B1, "zitarica");
		strcpy(niz[0].B2, "brasno");
		strcpy(niz[0].B3, "slava");
		strcpy(niz[0].B,"psenica");

		strcpy(niz[0].C1, "beba");
		strcpy(niz[0].C2, "stvoren");
		strcpy(niz[0].C3, "ponovo");
		strcpy(niz[0].C,"rodjen");

		strcpy(niz[0].D1, "bog");
		strcpy(niz[0].D2, "vaskrs");
		strcpy(niz[0].D3, "nazaret");
		strcpy(niz[0].D,"isus");
	
		strcpy(niz[0].Konacno,"bozic");
	}
	else if(m==2){
		strcpy(niz[0].A1, "voz");
		strcpy(niz[0].A2, "autobus");
		strcpy(niz[0].A3, "koncert");
		strcpy(niz[0].A,"karta");

		strcpy(niz[0].B1, "traka");
		strcpy(niz[0].B2, "horor");
		strcpy(niz[0].B3, "triler");
		strcpy(niz[0].B,"film");

		strcpy(niz[0].C1, "sto");
		strcpy(niz[0].C2, "drvena");
		strcpy(niz[0].C3, "noga");
		strcpy(niz[0].C,"stolica");

		strcpy(niz[0].D1, "bilbord");
		strcpy(niz[0].D2, "EPP");
		strcpy(niz[0].D3, "blok");
		strcpy(niz[0].D,"reklama");
	
		strcpy(niz[0].Konacno,"bioskop");
	}

	else if(m==3){
		strcpy(niz[0].A1, "decija");
		strcpy(niz[0].A2, "dnevna");
		strcpy(niz[0].A3, "spavaca");
		strcpy(niz[0].A,"soba");

		strcpy(niz[0].B1, "holivud");
		strcpy(niz[0].B2, "drzava");
		strcpy(niz[0].B3, "amerika");
		strcpy(niz[0].B,"kalifornija");

		strcpy(niz[0].C1, "sunce");
		strcpy(niz[0].C2, "crvena");
		strcpy(niz[0].C3, "nebo");
		strcpy(niz[0].C,"zvezda");

		strcpy(niz[0].D1, "more");
		strcpy(niz[0].D2, "seoski");
		strcpy(niz[0].D3, "vodic");
		strcpy(niz[0].D,"turizam");
	
		strcpy(niz[0].Konacno,"hotel");
	
	}
	else {
		exit(1);
	}


	/*Pocetak igre- provera unosa i izlaz*/

	for(i=0;i<21;i++){
		scanf("%s", s);
		for(j = 0;j<strlen(s); j++){
		  s[j] = toupper(s[j]);
		}
				
		if (strcmp(s, "A1") == 0) {
			strcpy(A1,niz[0].A1);
			ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

		}
		else if (strcmp(s, "A2") == 0) {
			strcpy(A2, niz[0].A2);
			ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

		}
		else if (strcmp(s, "A3") == 0) {
			strcpy(A3, niz[0].A3);
			ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);
		}
		else if (strcmp(s, "B1") == 0) {
			strcpy(B1, niz[0].B1);
			ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);
		}
		else if (strcmp(s, "B2") == 0) {
			strcpy(B2, niz[0].B2);
			ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);


		}
		else if (strcmp(s, "B3") == 0) {
			strcpy(B3, niz[0].B3);
			ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);
		}
		else if (strcmp(s, "C1") == 0) {
			strcpy(C1, niz[0].C1);
			ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

		}
		else if (strcmp(s, "C2") == 0) {
			strcpy(C2, niz[0].C2);
			ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

		}
		else if (strcmp(s, "C3") == 0) {
			strcpy(C3, niz[0].C3);
			ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

		}
		else if (strcmp(s, "D1") == 0) {
			strcpy(D1, niz[0].D1);
			ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

		}
		else if (strcmp(s, "D2") == 0) {
			strcpy(D2, niz[0].D2);
			ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

		}
		else if (strcmp(s, "D3") == 0) {
			strcpy(D3, niz[0].D3);
			ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

		}
		else if (strcmp(s, "A") == 0) {
			printf("\nUnesite vas odgovor\n");
			scanf("%s",odgovor1);
			for(k = 0;k<strlen(odgovor1); k++){
			 odgovor1[k]=tolower(odgovor1[k]);
			}
			if (strcmp(odgovor1, niz[0].A) == 0) {
				printf("\nVas odgovor je tacan\n");
				brojac2++;
				strcpy(A, niz[0].A);
				strcpy(A1,niz[0].A1);
				strcpy(A2,niz[0].A2);
				strcpy(A3,niz[0].A3);
				ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

			}
			else {
				printf("\nVas odgovor nije tacan\n");
				brojac++;
				ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

			}
		
		}
		else if (strcmp(s, "B") == 0) {
			printf("\nUnesite vas odgovor\n");
			scanf("%s",odgovor1);
			for(k = 0;k<strlen(odgovor1); k++){
			 odgovor1[k]=tolower(odgovor1[k]);
			}
			if (strcmp(odgovor1, niz[0].B) == 0) {
				printf("\nVas odgovor je tacan\n");
				brojac2++;
				strcpy(B, niz[0].B);
				strcpy(B1,niz[0].B1);
				strcpy(B2,niz[0].B2);
				strcpy(B3,niz[0].B3);
				ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

			}
			else {
				printf("\nVas odgovor nije tacan\n");
				brojac++;
				ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

			}
		
		}
		else if (strcmp(s, "C") == 0) {
			printf("\nUnesite vas odgovor\n");
			scanf("%s",odgovor1);
			for(k = 0;k<strlen(odgovor1); k++){
			 odgovor1[k]=tolower(odgovor1[k]);
			}
			if (strcmp(odgovor1, niz[0].C) == 0) {
				printf("\nVas odgovor je tacan\n");
				brojac2++;
				strcpy(C, niz[0].C);
				strcpy(C1,niz[0].C1);
				strcpy(C2,niz[0].C2);
				strcpy(C3,niz[0].C3);
				ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

			}
			else {
				printf("\nVas odgovor nije tacan\n");
				brojac++;
				ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

			}
		}

		else if (strcmp(s, "D") == 0) {
			printf("\nUnesite vas odgovor\n");
			scanf("%s",odgovor1);
			for(k = 0;k<strlen(odgovor1); k++){
			 odgovor1[k]=tolower(odgovor1[k]);
			}
			if (strcmp(odgovor1, niz[0].D) == 0) {
				printf("\nVas odgovor je tacan\n");
				brojac2++;
				strcpy(D, niz[0].D);
				strcpy(D1,niz[0].D1);
				strcpy(D2,niz[0].D2);
				strcpy(D3,niz[0].D3);
				ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

			}
			else {
				printf("\nVas odgovor nije tacan\n");
				brojac++;
				ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

			}
		}

		else if (strcmp(s, "KONACNO") == 0) {
			printf("\nUnesite vas odgovor\n");
			scanf("%s",odgovor1);
			for(k = 0;k<strlen(odgovor1); k++){
			 odgovor1[k]=tolower(odgovor1[k]);
			}
			if (strcmp(odgovor1, niz[0].Konacno) == 0) {
				printf("\nVas odgovor je tacan\n");
				flag=1;
				strcpy(Konacno, niz[0].Konacno);
				strcpy(A,niz[0].A);
				strcpy(A1,niz[0].A1);
				strcpy(A2,niz[0].A2);
				strcpy(A3,niz[0].A3);
				strcpy(B,niz[0].B);
				strcpy(B1,niz[0].B1);
				strcpy(B2,niz[0].B2);
				strcpy(B3,niz[0].B3);
				strcpy(C,niz[0].C);
				strcpy(C1,niz[0].C1);
				strcpy(C2,niz[0].C2);
				strcpy(C3,niz[0].C3);
				strcpy(D,niz[0].D);
				strcpy(D1,niz[0].D1);
				strcpy(D2,niz[0].D2);
				strcpy(D3,niz[0].D3);
				ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);
				printf("POBEDILI STE\n\n");
				break;

			}

			else {
				printf("\nVas odgovor nije tacan\n");
				ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);
				brojac++;

			}
		}

		else if((strcmp(s, "KRAJ") == 0)){
				break;
		}

		else{
			printf("\nUneli ste pogresan podatak!\n");
			brojac++;
			ispis( A1, A2, A3, B1, B2, B3, C1, C2, C3, D1, D2, D3, A, B, C, D,Konacno);

		}
	
		if(brojac==10){
			if(strcmp(A,niz[0].A)!=0 && strcmp(A1,niz[0].A1)!=0 && strcmp(A2,niz[0].A2)==0 && strcmp(A3,niz[0].A3)==0 || strcmp(B,niz[0].B)!=0 && strcmp(B1,niz[0].B1)!=0 && strcmp(B2,niz[0].B2)==0 && strcmp(B3,niz[0].B3)==0 || strcmp(C,niz[0].C)!=0 && strcmp(C1,niz[0].C1)!=0 && strcmp(C2,niz[0].C2)==0 && strcmp(C3,niz[0].C3)==0 || (strcmp(D,niz[0].D)!=0 && strcmp(D1,niz[0].D1)!=0 && strcmp(D2,niz[0].D2)==0 && strcmp(D3,niz[0].D3)==0)){
				rezultat-=1;
			}
			if(strcmp(A,niz[0].A)!=0 && strcmp(A1,niz[0].A1)==0 && strcmp(A2,niz[0].A2)!=0 && strcmp(A3,niz[0].A3)==0 || strcmp(B,niz[0].B)!=0 && strcmp(B1,niz[0].B1)==0 && strcmp(B2,niz[0].B2)!=0 && strcmp(B3,niz[0].B3)==0 || strcmp(C,niz[0].C)!=0 && strcmp(C1,niz[0].C1)==0 && strcmp(C2,niz[0].C2)!=0 && strcmp(C3,niz[0].C3)==0 || (strcmp(D,niz[0].D)!=0 && strcmp(D1,niz[0].D1)==0 && strcmp(D2,niz[0].D2)!=0 && strcmp(D3,niz[0].D3)==0)){
				rezultat-=1;
			}
			if(strcmp(A,niz[0].A)!=0 && strcmp(A1,niz[0].A1)==0 && strcmp(A2,niz[0].A2)==0 && strcmp(A3,niz[0].A3)!=0 || strcmp(B,niz[0].B)!=0 && strcmp(B1,niz[0].B1)==0 && strcmp(B2,niz[0].B2)==0 && strcmp(B3,niz[0].B3)!=0 || strcmp(C,niz[0].C)!=0 && strcmp(C1,niz[0].C1)==0 && strcmp(C2,niz[0].C2)==0 && strcmp(C3,niz[0].C3)!=0 || (strcmp(D,niz[0].D)!=0 && strcmp(D1,niz[0].D1)==0 && strcmp(D2,niz[0].D2)==0 && strcmp(D3,niz[0].D3)!=0)){
				rezultat-=1;
			}
			if(strcmp(A,niz[0].A)!=0 && strcmp(A1,niz[0].A1)!=0 && strcmp(A2,niz[0].A2)!=0 && strcmp(A3,niz[0].A3)==0 || strcmp(B,niz[0].B)!=0 && strcmp(B1,niz[0].B1)!=0 && strcmp(B2,niz[0].B2)!=0 && strcmp(B3,niz[0].B3)==0 || strcmp(C,niz[0].C)!=0 && strcmp(C1,niz[0].C1)!=0 && strcmp(C2,niz[0].C2)!=0 && strcmp(C3,niz[0].C3)==0 || (strcmp(D,niz[0].D)!=0 && strcmp(D1,niz[0].D1)!=0 && strcmp(D2,niz[0].D2)!=0 && strcmp(D3,niz[0].D3)==0)){
				rezultat-=2;
			}
			if(strcmp(A,niz[0].A)!=0 && strcmp(A1,niz[0].A1)==0 && strcmp(A2,niz[0].A2)!=0 && strcmp(A3,niz[0].A3)!=0 || strcmp(B,niz[0].B)!=0 && strcmp(B1,niz[0].B1)==0 && strcmp(B2,niz[0].B2)!=0 && strcmp(B3,niz[0].B3)!=0 || strcmp(C,niz[0].C)!=0 && strcmp(C1,niz[0].C1)==0 && strcmp(C2,niz[0].C2)!=0 && strcmp(C3,niz[0].C3)!=0 || (strcmp(D,niz[0].D)!=0 && strcmp(D1,niz[0].D1)==0 && strcmp(D2,niz[0].D2)!=0 && strcmp(D3,niz[0].D3)!=0)){
				rezultat-=2;
			}
			if(strcmp(A,niz[0].A)!=0 && strcmp(A1,niz[0].A1)!=0 && strcmp(A2,niz[0].A2)==0 && strcmp(A3,niz[0].A3)!=0 || strcmp(B,niz[0].B)!=0 && strcmp(B1,niz[0].B1)!=0 && strcmp(B2,niz[0].B2)==0 && strcmp(B3,niz[0].B3)!=0 || strcmp(C,niz[0].C)!=0 && strcmp(C1,niz[0].C1)!=0 && strcmp(C2,niz[0].C2)==0 && strcmp(C3,niz[0].C3)!=0 || (strcmp(D,niz[0].D)!=0 && strcmp(D1,niz[0].D1)!=0 && strcmp(D2,niz[0].D2)==0 && strcmp(D3,niz[0].D3)!=0)){
				rezultat-=2;
			}
			if(strcmp(A,niz[0].A)!=0 && strcmp(A1,niz[0].A1)!=0 && strcmp(A2,niz[0].A2)!=0 && strcmp(A3,niz[0].A3)!=0 || strcmp(B,niz[0].B)!=0 && strcmp(B1,niz[0].B1)!=0 && strcmp(B2,niz[0].B2)!=0 && strcmp(B3,niz[0].B3)!=0 || strcmp(C,niz[0].C)!=0 && strcmp(C1,niz[0].C1)!=0 && strcmp(C2,niz[0].C2)!=0 && strcmp(C3,niz[0].C3)!=0 || (strcmp(D,niz[0].D)!=0 && strcmp(D1,niz[0].D1)!=0 && strcmp(D2,niz[0].D2)!=0 && strcmp(D3,niz[0].D3)!=0)){
				rezultat-=3;
			}
			printf("\nPogresili ste pet puta, igra se zavrsava!\n\n");
			break;
		}
		if(strcmp(s,"A1")==0 || strcmp(s,"A2")==0 || strcmp(s,"A3")==0 || strcmp(s,"B1")==0 || strcmp(s,"B2")==0 || strcmp(s,"B3")==0 || strcmp(s,"C1")==0 || strcmp(s,"C2")==0 || strcmp(s,"C3")==0 || strcmp(s,"D1")==0 || strcmp(s,"D2")==0 || strcmp(s,"D3")==0 )
		{
			rezultat--;
		}
	}

	if(flag==1){
			rezultat-=0;
	}
	else if(brojac2==4){
			rezultat-=10;
	}
	else if(brojac2==3){
			rezultat-=11;
	}
	else if(brojac2==2){
			rezultat-=20;
	}
	else if(brojac2==1){
		rezultat-=21;
	}
	else if(brojac2==0){
			rezultat=0;
	}
	

	/*Tekstualna datoteka*/

	fptr1=fopen("resenje i rezultat.txt","w");
	if(fptr1==NULL){
		fprintf(stderr,"Neuspelo otvaranje datoteke\n");
		exit(1);
	}

	/*Ispis resenja i rezultata*/
	fprintf(fptr1,"A-%s\nB-%s\nC-%s\nD-%s\nKonacno-%s\n",niz[0].A,niz[0].B,niz[0].C,niz[0].D,niz[0].Konacno);
	fprintf(fptr1,"%d",rezultat);
	fclose(fptr1);
	free(niz);
	system("pause");

	return 0;
}

/*Funkcija koja ispisuje sva polja asocijacije bila ona otvorena ili zatvorena dobija ulazne parametre koji predstavljaju ta polja, poziva se iz glavne funkcije*/
void ispis(char A1[21],char A2[21],char A3[21],char B1[21],char B2[21],char B3[21],char C1[21],char C2[21],char C3[21],char D1[21],char D2[21],char D3[21],char A[21],char B[21],char C[21],char D[21],char Konacno[21]){
	//system("cls");
	printf("---------------------------------------------------------\n");
	printf("\n  %.*s\t\t\t\t %.*s",strlen(A1)+4,"____________________________",strlen(B1)+4,"__________________________________");
	printf("\n |_%*s%*s%*s_|\t\t\t\t|_%*s%*s%*s_|\n",1,"",1,A1,1,"",1,"",1,B1,1,"");
	printf("\n  %.*s\t\t\t\t %.*s",strlen(A2)+4,"____________________________",strlen(B2)+4,"__________________________________");
	printf("\n |_%*s%*s%*s_|\t\t\t\t|_%*s%*s%*s_|\n",1,"",1,A2,1,"",1,"",1,B2,1,"");
	printf("\n  %.*s\t\t\t\t %.*s",strlen(A3)+4,"____________________________",strlen(B3)+4,"__________________________________");
	printf("\n |_%*s%*s%*s_|\t\t\t\t|_%*s%*s%*s_|\n",1,"",1,A3,1,"",1,"",1,B3,1,"");
	printf("\n\t   %.*s\t\t %.*s",strlen(A)+4,"____________________________",strlen(B)+4,"__________________________________");
	printf("\n\t  |_%*s%*s%*s_|\t\t|_%*s%*s%*s_|\n",1,"",1,A,1,"",1,"",1,B,1,"");
	printf("\n  \t\t    %.*s",strlen(Konacno)+6,"____________________________");
	printf("\n \t\t   |__%*s%*s%*s__|\n",1,"",1,Konacno,1,"");
	printf("\n\t   %.*s\t\t %.*s",strlen(C)+4,"____________________________",strlen(D)+4,"__________________________________");
	printf("\n\t  |_%*s%*s%*s_|\t\t|_%*s%*s%*s_|\n",1,"",1,C,1,"",1,"",1,D,1,"");
	printf("\n  %.*s\t\t\t\t %.*s",strlen(C1)+4,"____________________________",strlen(D1)+4,"__________________________________");
	printf("\n |_%*s%*s%*s_|\t\t\t\t|_%*s%*s%*s_|\n",1,"",1,C1,1,"",1,"",1,D1,1,"");
	printf("\n  %.*s\t\t\t\t %.*s",strlen(C2)+4,"____________________________",strlen(D2)+4,"__________________________________");
	printf("\n |_%*s%*s%*s_|\t\t\t\t|_%*s%*s%*s_|\n",1,"",1,C2,1,"",1,"",1,D2,1,"");
	printf("\n  %.*s\t\t\t\t %.*s",strlen(C3)+4,"____________________________",strlen(D3)+4,"__________________________________");
	printf("\n |_%*s%*s%*s_|\t\t\t\t|_%*s%*s%*s_|\n",1,"",1,C3,1,"",1,"",1,D3,1,"");
	printf("\n---------------------------------------------------------\n");
	
}