#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<time.h> 
#include<ctype.h>

using namespace std;

struct promesani{
	char c;
};

struct karakteri{
	char c2;
};

struct polja{
	char a,b,c,d;
};

int igra2(struct karakteri *arr2,struct promesani *arr,int poeni,int poeni2,char broj_igraca);
int igra1(struct karakteri *arr2,struct promesani *arr,int poeni1,int poeni2,char broj_igraca);
char shuffle(char *znakovi);
void stampa(struct karakteri *arr2);
void sistem();
char* dodela(int poeni1,int poeni2,char pobednik[81]);
char *dodela2(int poeni1,int poeni2,char pobednik[81]);

int main(){
	int i,poeni1=0,poeni2=0;
	char znakovi[16+1],odgovor,broj_igraca;
	fstream f1,f2;
	promesani *arr;
	karakteri *arr2;

	f2.open("Znakovi.txt",ios::in);
	if(!f2){
		cout<<"Nije uspelo otvaranje datoteke"<<endl;
		exit(1);
	}
	f2>>znakovi;

	arr= new promesani[16];
	arr2=new karakteri[16];

	if(arr==NULL || arr2==NULL){
		cout<<"Nije uspela dodela memorije";	
		exit(1);
	}

	while(1){

		for(i=0;i<10;i++){																					//arr2[0].c2='0';	arr2[1].c2='1';	arr2[2].c2='2';	arr2[3].c2='3';	arr2[4].c2='4';	arr2[5].c2='5';									
				arr2[i].c2=(char)i+48;																		//arr2[6].c2='6';	arr2[7].c2='7';	arr2[8].c2='8';	arr2[9].c2='9';	arr2[10].c2='A';	arr2[11].c2='B';
		}																									//arr2[12].c2='C';	arr2[13].c2='D';	arr2[14].c2='E';	arr2[15].c2='F';
		for(i=10;i<16;i++){
				arr2[i].c2=(char)i+55;
		}
		cout<<"Unesite broj igraca (\"1\" za jednog igraca \"2\" za dva igraca)"<<endl;
		do{
			broj_igraca=getchar();
		}while(broj_igraca!='1' && broj_igraca!='2' || isspace(broj_igraca));
		getchar();

		cout<<"Unesite broj ili slovo polja koje zelite da otvorite\nZa kraj igre upisite slovo \"S\" \n";
		stampa(arr2);
		shuffle(znakovi);
		//cout<<znakovi<<endl;
		//cout<<rand()%16<<endl;
		for(i=0;i<16;i++){
			arr[i].c=znakovi[i];
			//cout<<arr[i].c<<endl;
		}
		if(broj_igraca=='2'){
			igra2(arr2,arr,poeni1,poeni2,broj_igraca);																//pokretanje igre

			f1.open("Poeni.txt",ios::in);
			if(!f1){
				cout<<"Nije uspelo otvaranje datoteke"<<endl;
				exit(1);
			}
			f1.seekp(-10,ios::end);																					//ide na kraj datoteke i 48 karaktera unazad i tek onda cita podatke
			f1>>poeni1>>poeni2;
			cout<<"\nIgrac jedan je osvojio "<<poeni1<<" poena"<<endl;
			cout<<"Igrac dva je osvojio "<<poeni2<<" poena"<<endl;
			if(poeni1>poeni2)
				cout<<"\nPobedio je prvi igrac!\n"<<endl;

			else if(poeni2>poeni1)
				cout<<"\nPobedio je drugi igrac!\n"<<endl;

			else
				cout<<"\nIzjednaceno je\n"<<endl;
		}
		else{
			igra1(arr2,arr,poeni1,poeni2,broj_igraca);													//pokretanje igre
			
			f1.open("Poeni.txt",ios::in);
			if(!f1){
				cout<<"Nije uspelo otvaranje datoteke"<<endl;
				exit(1);
			}
			f1.seekp(-10,ios::end);
			f1>>poeni1>>poeni2;
			cout<<"\nIgrac je osvojio "<<poeni1<<" poena"<<endl;
			cout<<"Kompjuter je osvojio "<<poeni2<<" poena"<<endl;
			if(poeni1>poeni2)
				cout<<"\nPobedio je igrac!\n"<<endl;

			else if(poeni2>poeni1)
				cout<<"\nPobedio je kompjuter!\n"<<endl;

			else
				cout<<"\nIzjednaceno je\n"<<endl;
		}
		f1.close();

		cout<<"Zelite li da igrate opet(Y\\N)"<<endl;
		odgovor=getchar();
		odgovor=toupper(odgovor);
		if(odgovor=='Y'){
			sistem();
			stampa(arr2);
		}
		else{
			cout<<"Igra se zavrsava"<<endl;
			break;
		}
	}
	f2.close();
	delete arr;
	delete arr2;
	return 0;
}

int igra2(struct karakteri *arr2,struct promesani *arr,int poeni1,int poeni2,char broj_igraca){
	int i,j,x,y,brojac=0,igrac=0/*,preskoci=0*/;
	char unos1,unos2,spasilac,linija[81],pobednik[81];
	fstream f1;

	f1.open("Poeni.txt",ios::app);																					//otvaranje datoteke
	if(!f1){
		cout<<"Nije uspelo otvaranje datoteke"<<endl;
		exit(1);
	}

	while(1){																										//pocetak igre
		if(igrac%2==0){
			cout<<"Igrac jedan je na potezu\n"<<endl;																	//koji igrac je na potezu
			igrac++;
		}else{
			cout<<"Igrac dva je na potezu\n"<<endl;
			igrac++;
		}

		/*if(preskoci==1){																							//preskace potez ukoliko je jedan igrac pogodio jer treba da igra dva puta zaredom (igrac++ je bolja opcija)
			preskoci=0;
			system("cls");
			stampa(arr2);
			igrac++;continue;
		}*/

		cin.getline(linija,81);																						//					Unos1
		if(strlen(linija)!=1){																						//provera unosa da li je unet jedan karakter
			if(strlen(linija)==0)
				cout<<"Morate uneti karakter"<<endl;
			else
				cout<<"Uneli ste pogresan broj karaktera"<<endl;
			sistem();
			stampa(arr2);
			igrac++;continue;
		}
		else
			unos1=linija[0];
		unos1=toupper(unos1);																						//pretvara unos u velika slova da bi korisnik mogao da unese i mala slova sa tastature
		if(unos1=='S')																								//proverava da li je unet stop kod
			break;
		y=unos1;	
		if(y > 47 && y < 58 ){																						//pretvara ASCII kod npr. broja 9(57) u broj 9			
			y = y - 48; 
		}
		else if (y > 64 && y < 71 ){																				//pretvara unos u broj npr.(pretvara A u broj 10),A=10(heksadecimalni zapis broja deset je A)
			y = y - 55;
		}
		if(arr2[y].c2!='\0' && y>-1 && y<17){
			spasilac=arr2[y].c2;																					//spasilac sluzi za pamcenje pocetnog stanja
			arr2[y].c2=arr[y].c;
			stampa(arr2);
		}
		else{
			cout<<"\nUneli ste pogresan podatak"<<endl;
			sistem();
			stampa(arr2);
			igrac++;continue;
		}

		cin.getline(linija,81);																						//					Unos2
		if(strlen(linija)!=1){																						//-//provera unosa da li je unet jedan karakter
			if(strlen(linija)==0)		
				cout<<"Morate uneti karakter"<<endl;
			else
				cout<<"Uneli ste pogresan broj karaktera"<<endl;
			sistem();
			arr2[y].c2=spasilac;																					//vracanje na pocetno stanje ukoliko je unet los broj karaktera a u prvom unosu je vec otvoreno polje
			stampa(arr2);
			igrac++;continue;																								//nastavak sa for petljom prebacuje na sledeci potez
		}
		else
			unos2=linija[0];
		unos2=toupper(unos2);																						//-//pretvara unos u velika slova da bi korisnik mogao da unese i mala slova sa tastature
		if(unos2=='S')																								//-//proverava da li je unet stop kod
			break;
		x=unos2;
		if( x > 47 && x < 58 ){																						//-//pretvara ASCII kod npr. broja 9(57) u broj 9
			x= x-48;
		}	
		else if ( x > 64 && x < 71 ){																				//-//pretvara unos u broj npr.(pretvara A u broj 10),A=10(heksadecimalni zapis broja deset je A)
			x=x-55;
		}
		if(arr2[x].c2!='\0' && x>-1 && x<17 && unos2!=unos1){														//provera ukoliko string nije prazan i ukoliko unos ima vrednost od 0 do 16
			arr2[x].c2=arr[x].c;																					//ubacuje znak u polje
			stampa(arr2);
		}
		else{
			cout<<"Uneli ste pogresan podatak"<<endl;
			sistem();
			arr2[y].c2=spasilac;																					//-//vracanje na pocetno stanje ukoliko je unet los broj karaktera a u prvom unosu je vec otvoreno polje		
			stampa(arr2);
			igrac++;continue;
		}

		if(arr2[y].c2==arr2[x].c2){																					//ukoliko su znakovi u otvorenim poljima isti
			cout<<arr2[y].c2<<" "<<arr2[x].c2<<" "<<y<<" "<<x<<"\n"<<endl;											//ispisuje unose
			arr2[y].c2='\0';																						//brise se sadrzaj polja
			arr2[x].c2='\0';
			if(igrac%2==0){																							//proverava koji igrac je pogodio i dodeljuje poene tom igracu s tim da je brojac vec inkrementiran i sada je drugi igrac deljiv sa 2
				cout<<"Pogodio je drugi igrac\N"<<endl;
				poeni2+=5;	
				igrac++;
				/*preskoci=1;*/																							//flag koji ce da preskoci potez igraca dva ukoliko je igrac jedan pogodio
			}
			else{
				cout<<"Pogodio je prvi igrac\N"<<endl;
				poeni1+=5;
				/*preskoci=1;*/
				igrac++;
			}
			sistem();
			stampa(arr2);
		}
		else{
			cout<<arr2[y].c2<<" "<<arr2[x].c2<<" "<<y<<" "<<x<<"\n"<<endl;											//ispisuje unose
			arr2[y].c2=unos1;																						//vracanje starih vrednosti u poljima
			arr2[x].c2=unos2;
			sistem();
			stampa(arr2);
		}
		for(j=0;j<15;j++){																							//provera da li su sva polja prazna
			if(arr2[j].c2=='\0'){
				brojac++;
			}
			else
				brojac=0;

			if(brojac==16){																							//ispisuje poene u datoteku ukoliko je kraj igre
				cout<<"\nOvoj igri dosao je kraj!"<<endl;
				strcpy(pobednik,dodela(poeni1,poeni2,pobednik));
				f1<<pobednik<<"Broj igraca je "<<broj_igraca<<"                             "<<"\n"<<poeni1<<" "<<poeni2<<endl;	
				f1.close();
				return 0;
			}
		}
	}
	strcpy(pobednik,dodela(poeni1,poeni2,pobednik));
	f1<<pobednik<<"Broj igraca je "<<broj_igraca<<"                             "<<"\n"<<poeni1<<" "<<poeni2<<endl;									//-//ispisuje poene u datoteku ukoliko je kraj igre
	
	f1.close();
	return 0;
}
int igra1(struct karakteri *arr2,struct promesani *arr,int poeni1,int poeni2,char broj_igraca){
	int i,j,x,y,brojac=0,igrac=0,preskoci1=0,preskoci2=0,random,random1,random2,broj_upisa=0,tezina;
	char unos1,unos2,spasilac,linija[81],pobednik[81],pogodak1='\0',pogodak2='\0',kompjuter[10];//linije[10][81];														//op1=otvoreno polje 1 
	fstream f1,f2,f3;
	polja *arr3;

	arr3= new polja[35];

	f1.open("Poeni.txt",ios::app);																					//otvaranje datoteke
	f2.open("Statistika.txt",ios::app);
	f3.open("Otvorena polja.txt",ios::out);
	if(!f1 || !f2 || !f3){
		cout<<"Nije uspelo otvaranje datoteke"<<endl;
		exit(1);
	}
	cout<<"\nIzaberite tezinu protivnika"<<endl<<"Easy(e)    Medium(m)    Hard(h)\n";
	do{
		tezina=getchar();
		tezina=toupper(tezina);
	}while(tezina!='E' && tezina!='M' && tezina!='H' || isspace(tezina));
	getchar();
	
	system("cls");
	stampa(arr2);

	while(1){													
		if(igrac%2==0){
			//preskoci1=0;
			cout<<"Igrac je na potezu\n"<<endl;				
			igrac++;

			cin.getline(linija,81);																					//					Unos1
			if(strlen(linija)!=1){																					//provera unosa da li je unet jedan karakter
				if(strlen(linija)==0)
					cout<<"Morate uneti karakter"<<endl;
				else
					cout<<"Uneli ste pogresan broj karaktera"<<endl;
				sistem();
				stampa(arr2);
				igrac++;continue;
			}
			else
				unos1=linija[0];

			unos1=toupper(unos1);																					//pretvara unos u velika slova da bi korisnik mogao da unese i mala slova sa tastature
			if(unos1=='S')																							//proverava da li je unet stop kod
				break;
			y=unos1;	
			if(y > 47 && y < 58 ){																					//pretvara ASCII kod npr. broja 9(57) u broj 9			
				y = y - 48; 
			}
			else if (y > 64 && y < 71 ){																			//pretvara unos u broj npr.(pretvara A u broj 10),A=10(heksadecimalni zapis broja deset je A)
				y = y - 55;
			}
			if(arr2[y].c2!='\0' && y>-1 && y<17){
				spasilac=arr2[y].c2;																				//spasilac sluzi za pamcenje pocetnog stanja
				arr2[y].c2=arr[y].c;
				stampa(arr2);
			}
			else{
				cout<<"\nUneli ste pogresan podatak"<<endl;
				sistem();
				stampa(arr2);
				igrac++;continue;
			}
				
			cin.getline(linija,81);																					//					Unos2
			if(strlen(linija)!=1){																					//-//provera unosa da li je unet jedan karakter
				if(strlen(linija)==0)		
					cout<<"Morate uneti karakter"<<endl;
				else
					cout<<"Uneli ste pogresan broj karaktera"<<endl;
				sistem();
				arr2[y].c2=spasilac;																				//vracanje na pocetno stanje ukoliko je unet los broj karaktera a u prvom unosu je vec otvoreno polje
				stampa(arr2);
				igrac++;continue;																							//nastavak sa for petljom prebacuje na sledeci potez
			}
			else
				unos2=linija[0];
			unos2=toupper(unos2);																					//-//pretvara unos u velika slova da bi korisnik mogao da unese i mala slova sa tastature
			if(unos2=='S')																							//-//proverava da li je unet stop kod
				break;
			x=unos2;
			if( x > 47 && x < 58 ){																					//-//pretvara ASCII kod npr. broja 9(57) u broj 9
				x= x-48;
			}	
			else if ( x > 64 && x < 71 ){																			//-//pretvara unos u broj npr.(pretvara A u broj 10),A=10(heksadecimalni zapis broja deset je A)
				x=x-55;
			}
			if(arr2[x].c2!='\0' && x>-1 && x<17 && x!=y){																	//provera ukoliko string nije prazan i ukoliko unos ima vrednost od 0 do 16
				arr2[x].c2=arr[x].c;																				//ubacuje znak u polje
				stampa(arr2);
			}
			else{
				cout<<"Uneli ste pogresan podatak\n"<<endl;
				sistem();
				arr2[y].c2=spasilac;																				//-//vracanje na pocetno stanje ukoliko je unet los broj karaktera a u prvom unosu je vec otvoreno polje		
				stampa(arr2);
				igrac++;continue;
			}

			if(arr2[y].c2==arr2[x].c2){																				//ukoliko su znakovi u otvorenim poljima isti
				cout<<arr2[y].c2<<" "<<arr2[x].c2<<" "<<y<<" "<<x<<"\n"<<endl;											//ispisuje unose
				arr2[y].c2='\0';																					//brise se sadrzaj polja
				arr2[x].c2='\0';
				cout<<"Pogodio je igrac"<<endl;
				poeni1+=5;	
				igrac++;																							//flag koji ce da preskoci potez igraca dva ukoliko je igrac jedan pogodio
				sistem();
				stampa(arr2);
			}
			else{
				cout<<arr2[y].c2<<" "<<arr2[x].c2<<" "<<unos1<<" "<<unos2<<"\n"<<endl;											//ispisuje unose
				arr2[y].c2=unos1;																					//vracanje starih vrednosti u poljima
				arr2[x].c2=unos2;
				sistem();
				stampa(arr2);
			}
			for(j=0;j<15;j++){																						//provera da li su sva polja prazna
				if(arr2[j].c2=='\0'){
					brojac++;
				}
				else
					brojac=0;

				if(brojac==16){																						//ispisuje poene u datoteku ukoliko je kraj igre
				strcpy(pobednik,dodela(poeni1,poeni2,pobednik));
				f1<<pobednik<<"Broj igraca je "<<broj_igraca<<"                             "<<"\n"<<poeni1<<" "<<poeni2<<endl;	
				f1.close();
				return 0;
				}
			}
		}	
		else if(igrac%2!=0 ){																									//KOMPJUTER
			/*preskoci2=0;	*/
			igrac++;
			srand(time(0));
			if(tezina=='H'){
				strcpy(kompjuter,"hard");
				random=rand()%6;																						//33% za gresku
			}
			else if(tezina=='M'){
				strcpy(kompjuter,"medium");
				random=rand()%4;																						//50% za gresku
			}
			else if(tezina=='E'){
				strcpy(kompjuter,"easy");
				random=rand()%3;																						//66% za gresku
			}
			//cout<<random;
			if(pogodak1!='\0' || pogodak2!='\0' && pogodak1!=pogodak2){
				//cout<<"Kompjuter je na potezu"<<endl;
				y=pogodak1;
				if(y > 47 && y < 58 ){																					//pretvara ASCII kod npr. broja 9(57) u broj 9			
				y = y - 48; 
				}
				else if (y > 64 && y < 71 ){																			//pretvara unos u broj npr.(pretvara A u broj 10),A=10(heksadecimalni zapis broja deset je A)
					y = y - 55;
				}
				x=pogodak2;
				if( x > 47 && x < 58 ){																					//-//pretvara ASCII kod npr. broja 9(57) u broj 9
					x= x-48;
				}	
				else if ( x > 64 && x < 71 ){																			//-//pretvara unos u broj npr.(pretvara A u broj 10),A=10(heksadecimalni zapis broja deset je A)
					x=x-55;
				}
				if(x!=y && arr2[y].c2!='\0' && arr2[x].c2!='\0' && random!=0 && random!=1){
					arr2[y].c2=arr[y].c;
					arr2[x].c2=arr[x].c;
					cout<<"\nKompjuter je pogodio\n"<<endl;
					cout<<y<<" "<<x<<" "<<arr2[x].c2<<" "<<arr2[y].c2<<"\n"<<endl;
					f3<<arr2[y].c2<<" "<<arr2[x].c2<<" "<<" "<<pogodak1<<" "<<pogodak2<<endl;
					f2<<arr2[y].c2<<" "<<arr2[x].c2<<" "<<" "<<pogodak1<<" "<<pogodak2<<endl;
					arr2[y].c2=arr[y].c;
					arr2[x].c2=arr[x].c;
					stampa(arr2);
					arr2[y].c2='\0';																					//brise se sadrzaj polja
					arr2[x].c2='\0';
					poeni2+=5;	
					igrac++;	
					pogodak1='\0';
					pogodak2='\0';
					sistem();
					stampa(arr2);
				}
				else{
					igrac++;
					pogodak1='\0';
					pogodak2='\0';
					//stampa(arr2);
					continue;
				}
				for(j=0;j<15;j++){																						//provera da li su sva polja prazna
					if(arr2[j].c2=='\0'){
						brojac++;
					}
					else
						brojac=0;

					if(brojac==16){																						//ispisuje poene u datoteku ukoliko je kraj igre
					strcpy(pobednik,dodela2(poeni1,poeni2,pobednik));
					f1<<pobednik<<"Broj igraca je "<<broj_igraca<<"                             "<<"\n"<<poeni1<<" "<<poeni2<<endl;	
					f1.close();
					return 0;
					}
				}
			}
			else{
				cout<<"Kompjuter tezine ("<<kompjuter<<") je na potezu"<<endl;
				srand(time(0)); 
				do{
					random1=rand()%16;
				}while(arr2[random1].c2=='\0');

				arr2[random1].c2=arr[random1].c;
				y=random1;
				if(y <10){																								//pretvara ASCII kod npr. broja 9(57) u broj 9			
					y = y + 48; 
				}
				else{																									//pretvara unos u broj npr.(pretvara A u broj 10),A=10(heksadecimalni zapis broja deset je A)
					y = y + 55;
				}

				do{
					random2=rand()%16;
				}while(arr2[random2].c2=='\0' || random1==random2);

				x=random2;
				if(x <10){																								//-//pretvara ASCII kod npr. broja 9(57) u broj 9
					x=x+48;		
				}	
				else{																									//-//pretvara unos u broj npr.(pretvara A u broj 10),A=10(heksadecimalni zapis broja deset je A)
					x=x+55;
				}

				arr2[random2].c2=arr[random2].c;																		//ubacuje znak u polje

				arr3[broj_upisa].a=arr2[random1].c2;
				arr3[broj_upisa].b=arr2[random2].c2;
				arr3[broj_upisa].c=(char)y;
				arr3[broj_upisa].d=(char)x;
				f3<<arr3[broj_upisa].a<<" "<<arr3[broj_upisa].b<<" "<<" "<<arr3[broj_upisa].c<<" "<<arr3[broj_upisa].d<<endl;
				broj_upisa++;
				stampa(arr2);
				/*int length = f3.tellg();
				cout<<length;*/
				//broj_upisa++;
				//f3.close();
				//stampa(arr2);
				//f3.seekg(f3.tellp());
				//f3.open("Otvorena polja.txt", ios::in);
				for(i=0;i<broj_upisa;i++){
				
					//f3.getline(linije[i],81);
					//f3>>linije[i][0]>>linije[i][1]>>linije[i][2]>>linije[i][3];
					////////////cout<<"\n\n"<<arr3[i].a<<" "<<arr3[i].b<<" "<<" "<<arr3[i].c<<" "<<arr3[i].d;
					for(j=0;j<broj_upisa;j++){
						if(arr3[i].a==arr3[j].b && arr3[i].c!=arr3[j].d){
							pogodak1=arr3[i].c;
							pogodak2=arr3[j].d;
						}
						else if(arr3[i].b==arr3[j].a && arr3[i].d!=arr3[j].c){
							pogodak1=arr3[i].d;
							pogodak2=arr3[j].c;
						}
						else if(arr3[i].a==arr3[j].a && arr3[i].c!=arr3[j].c){
							pogodak1=arr3[i].c;
							pogodak2=arr3[j].c;
						}
						else if(arr3[i].b==arr3[j].b && arr3[i].d!=arr3[j].d){
							pogodak1=arr3[i].d;
							pogodak2=arr3[j].d;
						}

					}
				}
				
				//	f3.seekp(f3.tellg());
				if(arr2[random1].c2==arr2[random2].c2 && random1!=random2 ){																	//ukoliko su znakovi u otvorenim poljima isti
					f2<<arr2[random1].c2<<" "<<arr2[random2].c2<<" "<<" "<<char(y)<<" "<<char(x)<<endl;
					cout<<"\nKompjuter je pogodio slucajno\n"<<endl;
					cout<<arr2[random1].c2<<" "<<arr2[random2].c2<<" "<<(char)y<<" "<<(char)x<<"\n"<<endl;
					arr2[random1].c2='\0';																				//brise se sadrzaj polja
					arr2[random2].c2='\0';
					poeni2+=5;	
					igrac++;																							//flag koji ce da preskoci potez igraca dva ukoliko je igrac jedan pogodio
					sistem();
					stampa(arr2);
				}	
				else{
					cout<<arr2[random1].c2<<" "<<arr2[random2].c2<<" "<<(char)y<<" "<<(char)x<<"\n"<<endl;
					arr2[random1].c2=(char)y;																			//vracanje starih vrednosti u poljima
					arr2[random2].c2=(char)x;
					sistem();
					stampa(arr2);
				}
			
				for(j=0;j<15;j++){																						//provera da li su sva polja prazna
					if(arr2[j].c2=='\0'){
						brojac++;
					}
					else
						brojac=0;

					if(brojac==16){																						//ispisuje poene u datoteku ukoliko je kraj igre
					strcpy(pobednik,dodela2(poeni1,poeni2,pobednik));
					f1<<pobednik<<"Broj igraca je "<<broj_igraca<<"                             "<<"\n"<<poeni1<<" "<<poeni2<<endl;	
					f1.close();
					return 0;
					}
				}
			}
		}
	}
	strcpy(pobednik,dodela2(poeni1,poeni2,pobednik));
	f1<<pobednik<<"Broj igraca je "<<broj_igraca<<"                             "<<"\n"<<poeni1<<" "<<poeni2<<endl;

	delete arr3;
	f1.close();
	f2.close();
	f3.close();
	return 0;
}

char shuffle(char *znakovi){				//nasumicno mesa znakove
		char temp,x;
        int j, i;
		srand(time(0)); 
		for (i = 15; i > 0; i--) {
            j = rand()%16;
            x = znakovi[i];
            znakovi[i] = znakovi[j];
            znakovi[j] = x;
			//cout<<znakovi[i]<<endl;
			//cout<<znakovi[j]<<endl;
        }
         return *znakovi;
}

void stampa(struct karakteri *arr2){						//stampa matricu 4x4 
	cout<<" _____\t _____\t _____ \t _____";
	cout<<"\n"<<"|__"<<arr2[0].c2<<"__|"<<"\t"<<"|__"<<arr2[1].c2<<"__|"<<"\t"<<"|__"<<arr2[2].c2<<"__|"<<"\t"<<"|__"<<arr2[3].c2<<"__|"<<endl;
	cout<<" _____\t _____\t _____ \t _____";
	cout<<"\n"<<"|__"<<arr2[4].c2<<"__|"<<"\t"<<"|__"<<arr2[5].c2<<"__|"<<"\t"<<"|__"<<arr2[6].c2<<"__|"<<"\t"<<"|__"<<arr2[7].c2<<"__|"<<endl;
	cout<<" _____\t _____\t _____ \t _____";
	cout<<"\n"<<"|__"<<arr2[8].c2<<"__|"<<"\t"<<"|__"<<arr2[9].c2<<"__|"<<"\t"<<"|__"<<arr2[10].c2<<"__|"<<"\t"<<"|__"<<arr2[11].c2<<"__|"<<endl;
	cout<<" _____\t _____\t _____ \t _____";
	cout<<"\n"<<"|__"<<arr2[12].c2<<"__|"<<"\t"<<"|__"<<arr2[13].c2<<"__|"<<"\t"<<"|__"<<arr2[14].c2<<"__|"<<"\t"<<"|__"<<arr2[15].c2<<"__|\n"<<endl;
}

void sistem(){									//pauzira sistem i cisti konzolu
		system("pause");
		system("cls");
}

char* dodela(int poeni1,int poeni2,char pobednik[81]){
	if(poeni1>poeni2)
		strcpy(pobednik,"Pobedio je prvi igrac! ");
	else if(poeni1<poeni2)
		strcpy(pobednik,"Pobedio je drugi igrac! ");
	else
		strcpy(pobednik,"Izjednaceno je! ");

	return pobednik;
}

char *dodela2(int poeni1,int poeni2,char pobednik[81]){
	if(poeni1>poeni2)
		strcpy(pobednik,"Pobedio je igrac! ");
	else if(poeni1<poeni2)
		strcpy(pobednik,"Pobedio je kompjuter! ");
	else
		strcpy(pobednik,"Izjednaceno je! ");

	return pobednik;
}
