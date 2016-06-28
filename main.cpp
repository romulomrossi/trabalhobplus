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
	sort (dados.begin(),dados.end());
	for( vector<Dados<string> >::iterator it=dados.begin(); it!=dados.end(); ++it )
		cout<<*it<<endl; 

	return 0;
}
