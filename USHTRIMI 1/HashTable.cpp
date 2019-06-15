#include <iostream>
#include <Math.h>
#include <fstream>
using namespace std;
typedef struct list{
	string celes;
	struct list *pas;
}list;

/*--------------------Gjendet Te Lista--------------------*/

bool gjendetNeListe(struct list *k,string fjala){
	if(k==NULL){
		return false;
	}
	struct list *tmp=k;
	while(tmp!=NULL){
		if(tmp->celes.compare(fjala)==0){
			return true;
		}
		tmp=tmp->pas;
	}
	return false;
}
 
 /*--------------------Shto Te Lista--------------*/
 
struct list* shtoNeListe(struct list *k,string vlera){
    if(gjendetNeListe(k,vlera))
    return k;
	struct list *tmp=new list();
	tmp->celes=vlera;
	tmp->pas=k;
	k=tmp;
	return k;
	
}

/*---------------------Hiq Nga Lista-------------------*/
			

struct list* hiqNgaLista(struct list *k,string vlera){
	if(!gjendetNeListe(k,vlera)){
		cout<<"Fjala nuk gjendet ne Liste";
		return k;
	}
	if(k==NULL){
		return k;
	}
    if(k->celes.compare(vlera)==0){
    	k=k->pas;
    	return k;
	}
	struct list *tmp=k;
	while(tmp->pas->celes.compare(vlera)!=0){
		tmp=tmp->pas;
	}
	tmp->pas=tmp->pas->pas;
	return k;
	
}


/*----------------- celesi --------------*/


int  celesInt(string fjala){
	
	int  i,s=0;
	for(i=0;i<fjala.length();i++){
		int vl=(int)fjala[i];
	    s+=vl*pow(3,i);
		}
		return s;
}


/*-------------------HASH CODE--------------*/


int hashCode(int vlera){
	if(vlera<0){
	return vlera%1000*(-1);
	}
	return vlera%1000;
}

/*---------------------Shto Ne Tabelen Hash-----------------*/

void shtoElement(struct list *T[],int N,string fjala){
	int pozicioni=hashCode(celesInt(fjala));
	T[pozicioni]=shtoNeListe(T[pozicioni],fjala);
	
}

/*-------------------Gjendet ne Tabelen Hash-----------------*/

bool gjendetNeHash(struct list *T[],int N,string fjala){
	int pozicioni=hashCode(celesInt(fjala));
	if(gjendetNeListe(T[pozicioni],fjala)){
		return true;
	}
	return false;
	
}

/*-------------Hiq nga Tabela Hash---------------------*/

void hiqElement(struct list *T[],int N,string fjala){
	if(!gjendetNeHash(T,N,fjala)){
		cout<<"Elementi nuk gjendet ne Tabelen Hash";
		return;
	}
	int pozicioni=hashCode(celesInt(fjala));
	T[pozicioni]=hiqNgaLista(T[pozicioni],fjala);
}

void afisho(list *T[],int N){
	for(int i=0;i<N;i++){
	struct list *tmp=T[i];
	while(tmp!=NULL){
		cout<<tmp->celes<<" ";
		tmp=tmp->pas;
	}
}
}
/*----Fillimi i Primary fUNCTION MAIN----*/

int main(){
	int i;
	struct list *TabeleHash[1000];//deklarimi i tabeles hash
	
/*------------------Mbushja ne fillim e tabeles me null-------------------*/

    for(i=0;i<1000;i++){
    	TabeleHash[i]=NULL;
	}

/*---------------Marrja e fjaleve nga skedari-------------*/

fstream in;
	in.open("skedar.txt",ios::in);
	string a;
	while(!in.eof()){
		in>>a;
		shtoElement(TabeleHash,1000,a);
	}

/*--------------------Afishimi-------------------------------*/

afisho(TabeleHash,1000);


	return 0;
}
/*--------------Mbyllja e funksionit kryesor MAIN---------------------*/





