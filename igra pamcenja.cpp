#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<time.h> 
using namespace std;

struct promesani{
	char c;
};

struct karakteri{
	char c2;
};

int igra(struct karakteri *arr2,struct promesani *arr,int poeni,int poeni2);
char shuffle(char *znakovi);
void stampa(struct karakteri *arr2);

int main(){
	int i,poeni1=0,poeni2=0;
	char znakovi[16+1]="+-*~=;$&+-*~=;$&",odgovor;
	fstream f1;
	promesani *arr;
	karakteri *arr2;

	arr= new promesani[16];
	arr2=new karakteri[16];

	if(arr==NULL || arr2==NULL){
		cout<<"Nije uspela dodela memorije";
		exit(1);
	}

	arr2[0].c2='0';
	arr2[1].c2='1';
	arr2[2].c2='2';
	arr2[3].c2='3';
	arr2[4].c2='4';
	arr2[5].c2='5';
	arr2[6].c2='6';
	arr2[7].c2='7';
	arr2[8].c2='8';
	arr2[9].c2='9';
	arr2[10].c2='A';
	arr2[11].c2='B';
	arr2[12].c2='C';
	arr2[13].c2='D';
	arr2[14].c2='E';
	arr2[15].c2='F';

	cout<<"Unesite broj ili slovo polja koje zelite da otvorite\nZa kraj igre upisite slovo \"S\" ";
	stampa(arr2);
	shuffle(znakovi);
	//cout<<znakovi<<endl;
	//cout<<rand()%16<<endl;
	for(i=0;i<16;i++){
		arr[i].c=znakovi[i];
		//cout<<arr[i].c<<endl;
	}

	igra(arr2,arr,poeni1,poeni2);

	f1.open("Poeni.txt",ios::in);
	f1>>poeni1>>poeni2;

	cout<<"\nIgrac jedan je osvojio "<<poeni1<<" poena"<<endl;
	cout<<"Igrac dva je osvojio "<<poeni2<<" poena"<<endl;
	if(poeni1>poeni2)
		cout<<"\nPobedio je prvi igrac!\n"<<endl;
	else if(poeni2>poeni1)
		cout<<"\nPobedio je drugi igrac!\n"<<endl;
	else 
		cout<<"\nIzjednaceno je\n"<<endl;

	f1.close();
	delete arr;
	delete arr2;

	cout<<"Zelite li da igrate opet(Y\\N)"<<endl;
	cin>>odgovor;
	odgovor=toupper(odgovor);
	if(odgovor=='Y'){
		sistem();
		main();
	}
	else{
		exit(1);
	}

	return 0;
}

int igra(struct karakteri *arr2,struct promesani *arr,int poeni1,int poeni2){
	int i,j,x,y,brojac=0,igrac=0;
	char unos1,unos2,spasilac,linija[81];
	fstream f1;

	f1.open("Poeni.txt",ios::out);								//otvaranje datoteke
	if(!f1){
		cout<<"Nije uspelo otvaranje datoteke"<<endl;
	}

	while(1){													//pocetak igre
		if(igrac%2==0){
			cout<<"Igrac jedan je na potezu"<<endl;				//koji igrac je na potezu
			igrac++;
		}else{
			cout<<"Igrac dva je na potezu"<<endl;
			igrac++;
		}

		cin.getline(linija,81);									//					Unos1
		if(strlen(linija)!=1){									//provera unosa da li je unet jedan karakter
			if(strlen(linija)==0)
				cout<<"Morate uneti karakter"<<endl;
			else
				cout<<"Uneli ste pogresan broj karaktera"<<endl;
			sistem();
			stampa(arr2);
			continue;
		}
		else
			unos1=linija[0];
		unos1=toupper(unos1);									//pretvara unos u velika slova da bi korisnik mogao da unese i mala slova sa tastature
		if(unos1=='S')											//proverava da li je unet stop kod
			break;
		y=unos1;	
		if(y > 47 && y < 58 ){									//pretvara ASCII kod npr. broja 9(57) u broj 9			
			y = y - 48; 
		}
		else if (y > 64 && y < 71 ){							//pretvara unos u broj npr.(pretvara A u broj 10),A=10(heksadecimalni zapis broja deset je A)
			y = y - 55;
		}
		if(arr2[y].c2!='\0' && y>-1 && y<17){
			spasilac=arr2[y].c2;								//spasilac sluzi za pamcenje pocetnog stanja
			arr2[y].c2=arr[y].c;
			stampa(arr2);
		}
		else{
			cout<<"\nUneli ste pogresan podatak"<<endl;
			sistem();
			stampa(arr2);
			continue;
		}

		cin.getline(linija,81);										//					Unos2
		if(strlen(linija)!=1){										//-//provera unosa da li je unet jedan karakter
			if(strlen(linija)==0)		
				cout<<"Morate uneti karakter"<<endl;
			else
				cout<<"Uneli ste pogresan broj karaktera"<<endl;
			sistem();
			arr2[y].c2=spasilac;									//vracanje na pocetno stanje ukoliko je unet los broj karaktera a u prvom unosu je vec otvoreno polje
			stampa(arr2);
			continue;												//nastavak sa for petljom prebacuje na sledeci potez
		}
		else
			unos2=linija[0];
		unos2=toupper(unos2);										//-//pretvara unos u velika slova da bi korisnik mogao da unese i mala slova sa tastature
		if(unos2=='S')												//-//proverava da li je unet stop kod
			break;
		x=unos2;
		if( x > 47 && x < 58 ){										//-//pretvara ASCII kod npr. broja 9(57) u broj 9
			x= x-48;
		}	
		else if ( x > 64 && x < 71 ){								//-//pretvara unos u broj npr.(pretvara A u broj 10),A=10(heksadecimalni zapis broja deset je A)
			x=x-55;
		}
		if(arr2[x].c2!='\0' && x>-1 && x<17){						//provera ukoliko string nije prazan i ukoliko unos ima vrednost od 0 do 16
			arr2[x].c2=arr[x].c;									//ubacuje znak u polje
			stampa(arr2);
		}
		else{
			cout<<"Uneli ste pogresan podatak"<<endl;
			sistem();
			arr2[y].c2=spasilac;									//-//vracanje na pocetno stanje ukoliko je unet los broj karaktera a u prvom unosu je vec otvoreno polje		
			stampa(arr2);
			continue;
		}
		cout<<x<<" "<<y<<endl;										//ispisuje unose

		if(arr2[y].c2==arr2[x].c2){									//ukoliko su znakovi u otvorenim poljima isti
			arr2[y].c2='\0';										//brise se sadrzaj polja
			arr2[x].c2='\0';
			if(igrac%2==0)											//proverava koji igrac je pogodio i dodeljuje poene tom igracu s tim da je brojac vec inkrementiran i sada je drugi igrac deljiv sa 2
				cout<<"\nPogodio je drugi igrac"<<endl;
			else 
				cout<<"\nPogodio je prvi igrac"<<endl;
			sistem();
			stampa(arr2);
			if(igrac%2==0)
				poeni2+=5;
			else 
				poeni1+=5;
		}
		else{
			arr2[y].c2=unos1;										//vracanje starih vrednosti u poljima
			arr2[x].c2=unos2;
			sistem();
			stampa(arr2);
		}
		for(j=0;j<15;j++){											//provera da li su sva polja prazna
			if(arr2[j].c2=='\0'){
				brojac++;
			}
			else
				brojac=0;

			if(brojac==16){											//ispisuje poene u datoteku ukoliko je kraj igre
				cout<<"\nOvoj igri dosao je kraj!"<<endl;
				f1<<poeni1<<" "<<poeni2<<endl;
				f1.close();
				return 0;
			}
		}
	}
	f1<<poeni1<<" "<<poeni2<<endl;									//-//ispisuje poene u datoteku ukoliko je kraj igre
	f1.close();
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
        }
         return *znakovi;
}

void stampa(struct karakteri *arr2){						//stampa matricu 4x4 
	cout<<"\n ___\t ___\t ___ \t ___";
	cout<<"\n"<<"|_"<<arr2[0].c2<<"_|"<<"\t"<<"|_"<<arr2[1].c2<<"_|"<<"\t"<<"|_"<<arr2[2].c2<<"_|"<<"\t"<<"|_"<<arr2[3].c2<<"_|"<<endl;
	cout<<" ___\t ___\t ___ \t ___";
	cout<<"\n"<<"|_"<<arr2[4].c2<<"_|"<<"\t"<<"|_"<<arr2[5].c2<<"_|"<<"\t"<<"|_"<<arr2[6].c2<<"_|"<<"\t"<<"|_"<<arr2[7].c2<<"_|"<<endl;
	cout<<" ___\t ___\t ___ \t ___";
	cout<<"\n"<<"|_"<<arr2[8].c2<<"_|"<<"\t"<<"|_"<<arr2[9].c2<<"_|"<<"\t"<<"|_"<<arr2[10].c2<<"_|"<<"\t"<<"|_"<<arr2[11].c2<<"_|"<<endl;
	cout<<" ___\t ___\t ___ \t ___";
	cout<<"\n"<<"|_"<<arr2[12].c2<<"_|"<<"\t"<<"|_"<<arr2[13].c2<<"_|"<<"\t"<<"|_"<<arr2[14].c2<<"_|"<<"\t"<<"|_"<<arr2[15].c2<<"_|\n"<<endl;
}

void sistem(){									//pauzira sistem i cisti konzolu
		system("pause");
		system("cls");
}
