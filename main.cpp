#include <iostream>
#include <string>
#include "lerArquivo.h"

#include <stdlib.h>
#include <algorithm>

//#include<quicksort>
using namespace std;

int main(int argc, char ** argv){
	vector<Dados<string> > dados;
	int digitos = atol(argv[2]);

	//dados = carregaArquivo("teste.csv",atol(argv[1]),digitos==0 ? -1 : digitos);
dados = carregaArquivo("testemenor",atol(argv[1]),digitos==0 ? -1 : digitos);
//	for( vector<Dados<string> >::iterator it=dados.begin(); it!=dados.end(); ++it )
//		cout<<*it<<endl;
	dados.pop_back();
	sort (dados.begin(),dados.end());
	//for( auto it = dados.begin(); it!=dados.end(); ++it )
	for( vector<Dados<string> >::iterator it=dados.begin(); it!=dados.end(); ++it )
		cout<<*it<<endl;

		cout<<endl<<"/\antes depois\\/ "<<endl;

	vector<Dados<string> >::iterator atual = dados.begin();
	vector<Dados<string> >::iterator temp;
	bool flag=false;
//	dados.erase(dados.begin());
//	cout<<atual<<endl;
	for( vector<Dados<string> >::iterator it=dados.begin()+1; it!=dados.end(); ++it ){
		if( flag ){
			dados.erase(temp);
			flag=false;
			cout<<"apagou\n";
		}
		cout<<"comparando: "<<atual->getChave()<<" e "<<it->getChave();
	 	if(*atual==*it){
			atual->addRef( it->getOffsets().back() );
			it->clearOffsets();
			temp=it;
			flag=true;
			cout<<"= true"<<endl;
	 	}else{
			atual = it ;
			cout<<"= false"<<endl;
	 	}
	 }
cout<<"chegou aqui!!!!"<<endl;
	 dados[0].getOffsets().clear();
		 for( vector<Dados<string> >::iterator it=dados.begin(); it!=dados.end(); ++it )
		 	cout<<*it<<endl;

	return 0;
}
