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

	dados = carregaArquivo("teste.csv",atol(argv[1]),digitos==0 ? -1 : digitos);

//	for( vector<Dados<string> >::iterator it=dados.begin(); it!=dados.end(); ++it )
//		cout<<*it<<endl;
	dados.pop_back();
	sort (dados.begin(),dados.end());
	//for( auto it = dados.begin(); it!=dados.end(); ++it )
//	for( vector<Dados<string> >::iterator it=dados.begin(); it!=dados.end(); ++it )
	//	cout<<*it<<endl;

	Dados<string> atual = dados[0];
	dados.erase(dados.begin());
	cout<<atual<<endl;
	cout<<"novo primeiro"<<dados[0]<<endl;
	// for( vector<string>::iterator it=dados.begin(); it!=dados.end(); ++it ){
	// 	if(*atual==*it){
	// 		atual->addRef(it->getOffsets()[0] );
	//
	// 	}else{
	// 		atual=it;
	// 	}
	// }

		// for( vector<Dados<string> >::iterator it=dados.begin(); it!=dados.end(); ++it )
		// 	cout<<*it<<endl;

	return 0;
}
