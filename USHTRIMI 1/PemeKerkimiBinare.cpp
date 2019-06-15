#include<iostream>
#include<Math.h>
#include<fstream>
using namespace std;
  typedef struct peme{
  	string fjala;
  	struct peme *a,*b,*c;
  }peme;
  	
  
  
  peme *krijoNyje(string fjala){
  	
  	peme *kulm=new peme;
  	kulm->fjala=fjala;
  	kulm->a=NULL;
  	kulm->b=NULL;
  	kulm->c=NULL;
  	return kulm;
  }

 
  
  
  /*-------------------------SHTIMI NE KULM-----------------*/

  
  peme *add(peme *T,string fjala){
  	peme *kulm=krijoNyje(fjala);
  	peme *y=NULL;
  	peme *tmp=T;
  	
  	while(tmp!=NULL){
  		y=tmp;
  		if(kulm->fjala.compare(tmp->fjala)<0){
  			tmp=tmp->b;
		  }
  		else if(kulm->fjala.compare(tmp->fjala)>0){
  			tmp=tmp->c;
		  }
		  else{
		  	return T;
		  }
	  }
  	kulm->a=y;
  	if(y==NULL){
  		T=kulm;
  		return T;
	  }
	else if(kulm->fjala.compare(y->fjala)<0){
	  	y->b=kulm;
	  	return T;
	  }
    else{
	  	y->c=kulm;
	  	return T;
	  }
  } 
  
 /*---------------------AFISHIMI---------------------*/
  
  void afisho(peme *k){
  	if(k==NULL)
  	return;
  	
  	afisho(k->b);
  	cout<<k->fjala<<" ";
  	afisho(k->c);
  }
  
  
  
  
  
/*----- Funksioni kryesor MAIN-------*/
  
  int main(){
  	peme *rr=NULL;
  fstream in;
	in.open("skedar.txt",ios::in);
	string a;
	while(!in.eof()){
		in>>a;
		rr=add(rr,a);
	}

	
	afisho(rr);
  }
