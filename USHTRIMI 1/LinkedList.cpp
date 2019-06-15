#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
typedef struct list{
	string m;
	struct list *pas;
}list;



bool gjendet(list *k,string fjala){
	if(k==NULL){
		return false;
	}
	struct list *tmp=k;
	while(tmp!=NULL){
		if(tmp->m.compare(fjala)==0){
			return true;
		}
		tmp=tmp->pas;
	}
	return false;
}

list *add(list *k,string vlera){
    if(gjendet(k,vlera))
    return k;
	struct list *tmp=new list();
	tmp->m=vlera;
	tmp->pas=k;
	k=tmp;
	return k;
}
void afisho(list *k){
	struct list *tmp=k;
	while(tmp!=NULL){
		
		cout<<tmp->m<<" ";
		tmp=tmp->pas;
		
	}
		
}



int main(){
	

	list *k=NULL;
	fstream in;
	in.open("skedar.txt",ios::in);
	string m;
	while(!in.eof()){
		in>>m;
		k=add(k,m);
	}
	afisho(k);
	
	return 0;
}
