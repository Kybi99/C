#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct pitanja{
	char pitanje[81];
};

struct Nodgovori{
	char odgovor1[21],odgovor2[21],odgovor3[21];
};

struct Todgovori{
	char odgovor4[21];
};

/*void Ocisti();*/
void Pisi(int brojac , struct pitanja *pok1,struct Nodgovori *pok2,struct Todgovori *pok3);

main(){
	int i,brojac2=0,brojac3=0,iznos=0,flag=0,brojac=0;
	char unos[21],unos2[21],unos3[21];
	struct pitanja *pok1;
	struct Nodgovori *pok2;
	struct Todgovori *pok3;
	FILE *dat;

	pok1=(struct pitanja*)malloc(11*sizeof(struct pitanja));
	pok2=(struct Nodgovori*)malloc(11*sizeof(struct Nodgovori));
	pok3=(struct Todgovori*)malloc(11*sizeof(struct Todgovori));

	if (pok1 == NULL || pok2==NULL || pok3==NULL) {
		printf("Neuspesna dodela memorije");
		exit(1);
	}
	strcpy(pok1[0].pitanje,"ovo je prvo pitanje");
	strcpy(pok1[1].pitanje,"ovo je drugo pitanje");
	strcpy(pok1[2].pitanje,"ovo je trece pitanje");
	strcpy(pok1[3].pitanje,"ovo je cetvrto pitanje");
	strcpy(pok1[4].pitanje,"ovo je peto pitanje");
	strcpy(pok1[5].pitanje,"ovo je sesto pitanje");
	strcpy(pok1[6].pitanje,"ovo je sedmo pitanje");
	strcpy(pok1[7].pitanje,"ovo je osmo pitanje");
	strcpy(pok1[8].pitanje,"ovo je deveto pitanje");
	strcpy(pok1[9].pitanje,"ovo je deseto pitanje");
	strcpy(pok1[10].pitanje,"ovo je extra pitanje");


	strcpy(pok2[0].odgovor1,"prvi");
	strcpy(pok2[0].odgovor2,"drugi");
	strcpy(pok2[0].odgovor3,"treci");
	strcpy(pok3[0].odgovor4,"tacan");

	strcpy(pok2[1].odgovor1,"prvii");
	strcpy(pok2[1].odgovor2,"drugii");
	strcpy(pok2[1].odgovor3,"trecii");
	strcpy(pok3[1].odgovor4,"tacan");

	strcpy(pok2[2].odgovor1,"prviii");
	strcpy(pok2[2].odgovor2,"drugiii");
	strcpy(pok2[2].odgovor3,"treciii");
	strcpy(pok3[2].odgovor4,"tacan");

	strcpy(pok2[3].odgovor1,"prvi");
	strcpy(pok2[3].odgovor2,"drugi");
	strcpy(pok2[3].odgovor3,"treci");
	strcpy(pok3[3].odgovor4,"tacan");

	strcpy(pok2[4].odgovor1,"prvii");
	strcpy(pok2[4].odgovor2,"drugii");
	strcpy(pok2[4].odgovor3,"trecii");
	strcpy(pok3[4].odgovor4,"tacan");

	strcpy(pok2[5].odgovor1,"prvi");
	strcpy(pok2[5].odgovor2,"drugi");
	strcpy(pok2[5].odgovor3,"treci");
	strcpy(pok3[5].odgovor4,"tacan");

	strcpy(pok2[6].odgovor1,"prvii");
	strcpy(pok2[6].odgovor2,"drugii");
	strcpy(pok2[6].odgovor3,"trecii");
	strcpy(pok3[6].odgovor4,"tacan");

	strcpy(pok2[7].odgovor1,"prviii");
	strcpy(pok2[7].odgovor2,"drugiii");
	strcpy(pok2[7].odgovor3,"treciii");
	strcpy(pok3[7].odgovor4,"tacan");

	strcpy(pok2[8].odgovor1,"prvi");
	strcpy(pok2[8].odgovor2,"drugi");
	strcpy(pok2[8].odgovor3,"treci");
	strcpy(pok3[8].odgovor4,"tacan");

	strcpy(pok2[9].odgovor1,"prvii");
	strcpy(pok2[9].odgovor2,"drugii");
	strcpy(pok2[9].odgovor3,"trecii");
	strcpy(pok3[9].odgovor4,"tacan");

	strcpy(pok2[10].odgovor1,"p");
	strcpy(pok2[10].odgovor2,"d");
	strcpy(pok2[10].odgovor3,"t");
	strcpy(pok3[10].odgovor4,"tacan");

	printf("\nSvaku pomoc mozete iskoristiti samo jednom\n");
	for(i=0;i<10;i++){
		/*Ocisti();*/
		Pisi(brojac,pok1,pok2,pok3);
		printf("\nIskoriscene pomoci su :\t");
		if(brojac2==1){
			printf("polapola\t");
		}
		if(brojac3==1){
			printf("zamena\t");
		}
		printf("\n");
		printf("Unesite vas odgovor(Npr.\"prvi\" ili za pomoc(\"polapola\",\"zamena\")): \n\n");

		scanf("%s",unos);

		if(strcmp(unos,pok3[brojac].odgovor4)==0){
			printf("\nOdgovor je tacan\n");
			flag=1;
			brojac++;
		}
		else if(strcmp(unos,"polapola")==0){
			strcpy(pok2[brojac].odgovor2,"");
			strcpy(pok2[brojac].odgovor3,"");
			Pisi(brojac,pok1,pok2,pok3);
			printf("\nUnesite vas odgovor:(Npr.\"prvi\" ili za pomoc(\"polapola\",\"zamena\")) \n");
			scanf("%s",unos2);
			if(strcmp(unos2,pok3[brojac].odgovor4)==0){
				printf("\nOdgovor je tacan\n");
				flag=1;
				brojac++;
				brojac2++;
			}
			else if(strcmp(unos2,"zamena")==0){
				strcpy(pok1[brojac].pitanje,pok1[10].pitanje);
				strcpy(pok2[brojac].odgovor1,pok2[10].odgovor1);
				strcpy(pok2[brojac].odgovor2,pok2[10].odgovor2);
				strcpy(pok2[brojac].odgovor3,pok2[10].odgovor3);
				strcpy(pok3[brojac].odgovor4,pok3[10].odgovor4);
				Pisi(brojac,pok1,pok2,pok3);
				printf("\nUnesite vas odgovor:(Npr.\"prvi\" ili za pomoc(\"polapola\",\"zamena\")) \n");
				scanf("%s",unos3);
					if(strcmp(unos3,pok3[brojac].odgovor4)==0){
						printf("\nOdgovor je tacan\n");
						flag=1;
						brojac++;
						brojac3++;
					}
				}	
		}
		else if(strcmp(unos,"zamena")==0){
			strcpy(pok1[brojac].pitanje,pok1[10].pitanje);
			strcpy(pok2[brojac].odgovor1,pok2[10].odgovor1);
			strcpy(pok2[brojac].odgovor2,pok2[10].odgovor2);
			strcpy(pok2[brojac].odgovor3,pok2[10].odgovor3);
			strcpy(pok3[brojac].odgovor4,pok3[10].odgovor4);
			Pisi(brojac,pok1,pok2,pok3);
			printf("\nUnesite vas odgovor:(Npr.\"prvi\" ili za pomoc(\"polapola\",\"zamena\")) \n");
			scanf("%s",unos2);
			if(strcmp(unos2,pok3[brojac].odgovor4)==0){
				printf("\nOdgovor je tacan\n");
				flag=1;
				brojac++;
				brojac3++;
			}
			else if(strcmp(unos2,"polapola")==0){
				strcpy(pok2[brojac].odgovor2,"");
				strcpy(pok2[brojac].odgovor3,"");
				Pisi(brojac,pok1,pok2,pok3);
				printf("\nUnesite vas odgovor:(Npr.\"prvi\" ili za pomoc(\"polapola\",\"zamena\")) \n");
				scanf("%s",unos3);
					if(strcmp(unos3,pok3[brojac].odgovor4)==0){
						printf("\nOdgovor je tacan\n");
						flag=1;
						brojac++;
						brojac2++;
					}
			}		

		}
		else{
			printf("\nOdgovor nije tacan nazalost igra se zavrsava\n");
			flag=0;
		}
		if(brojac2==2 || brojac3==2 || flag==0 || brojac==10){
			break;
		}
		
	}
	if(brojac<3){
		iznos=0;
	}
	else if(brojac<6){
		iznos=20000;
	}
	else if(brojac<7){
		iznos=200000;
	}
	else if(brojac<9){
		iznos=800000;
	}
	else if(brojac==10){
		iznos=1500000;
	}

	dat=fopen("Osvojeni iznos.txt","w");
	if(dat==NULL){
		fprintf(stderr,"Neuspelo otvaranje datoteke\n");
		exit(1);
	}

	fprintf(dat,"Osvojili ste %d dinara",iznos);
	fclose(dat);

	free(pok1);
	free(pok2);
	free(pok3);

	return 0;
}

void Pisi(int brojac, struct pitanja *pok1,struct Nodgovori *pok2,struct Todgovori *pok3){
	if(brojac==0){
		printf("\n\t%s\n\n",pok1[brojac].pitanje);
		printf("A.%s\nB.%s\nC.%s\nD.%s",pok2[brojac].odgovor1,pok2[brojac].odgovor2,pok2[brojac].odgovor3,pok3[brojac].odgovor4);
		printf("\n\nIznos(5000)\n");
	}
	else if(brojac==1){
		printf("\n\t%s\n\n",pok1[brojac].pitanje);
		printf("A.%s\nB.%s\nC.%s\nD.%s",pok2[brojac].odgovor1,pok3[brojac].odgovor4,pok2[brojac].odgovor2,pok2[brojac].odgovor3);
		printf("\n\nIznos(10000)\n");
	}
	else if(brojac==2){
		printf("\n\t%s\n\n",pok1[brojac].pitanje);
		printf("A.%s\nB.%s\nC.%s\nD.%s",pok2[brojac].odgovor2,pok2[brojac].odgovor1,pok3[brojac].odgovor4,pok2[brojac].odgovor3);
		printf("\nZagarantovano(20000)\n");
	}
	else if(brojac==3){
		printf("\n\t%s\n\n",pok1[brojac].pitanje);
		printf("A.%s\nB.%s\nC.%s\nD.%s",pok2[brojac].odgovor1,pok3[brojac].odgovor4,pok2[brojac].odgovor2,pok2[brojac].odgovor3);
		printf("\n\nIznos(50000)\n");
	}
	else if(brojac==4){
		printf("\n\t%s\n\n",pok1[brojac].pitanje);
		printf("A.%s\nB.%s\nC.%s\nD.%s",pok3[brojac].odgovor4,pok2[brojac].odgovor1,pok2[brojac].odgovor2,pok2[brojac].odgovor3);
		printf("\n\nIznos(100000)\n");
	}
	else if(brojac==5){
		printf("\n\t%s\n\n",pok1[brojac].pitanje);
		printf("A.%s\nB.%s\nC.%s\nD.%s",pok2[brojac].odgovor1,pok2[brojac].odgovor2,pok2[brojac].odgovor3,pok3[brojac].odgovor4);
		printf("\n\nZagarantovano(200000)\n");
	}
	else if(brojac==6){
		printf("\n\t%s\n\n",pok1[brojac].pitanje);
		printf("A.%s\nB.%s\nC.%s\nD.%s",pok2[brojac].odgovor1,pok2[brojac].odgovor2,pok2[brojac].odgovor3,pok3[brojac].odgovor4);
		printf("\n\nIznos(400000)\n");
	}
	else if(brojac==7){
		printf("\n\t%s\n\n",pok1[brojac].pitanje);
		printf("A.%s\nB.%s\nC.%s\nD.%s",pok2[brojac].odgovor1,pok3[brojac].odgovor4,pok2[brojac].odgovor2,pok2[brojac].odgovor3);
		printf("\nZagarantovano(800000)\n");
	}
	else if(brojac==8){
		printf("\n\t%s\n\n",pok1[brojac].pitanje);
		printf("A.%s\nB.%s\nC.%s\nD.%s",pok2[brojac].odgovor1,pok2[brojac].odgovor2,pok3[brojac].odgovor4,pok2[brojac].odgovor3);
		printf("\n\nIznos(1000000)\n");
	}
	else if(brojac==9){
		printf("\n\t%s\n\n",pok1[brojac].pitanje);
		printf("A.%s\nB.%s\nC.%s\nD.%s",pok3[brojac].odgovor4,pok2[brojac].odgovor1,pok2[brojac].odgovor2,pok2[brojac].odgovor3);
		printf("\n\nIznos(1500000)\n");
	}

}

/*void Ocisti(){
        system("cls");
*/