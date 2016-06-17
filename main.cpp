#include <iostream>
#include <string>
#include "lerArquivo.h"

#include <stdlib.h>
#include <algorithm>

//#include<quicksort>
using namespace std;

int main(int argc, char ** argv){
	
	vector<Dados<string> > dados;
	dados = carregaArquivo("teste.csv",atol(argv[1]),atol(argv[2]));

//	for( vector<Dados<string> >::iterator it=dados.begin(); it!=dados.end(); ++it )
//		cout<<*it<<endl;
//		cout<<"chave:"<<dados[i].getChave()<<"\n offsets:"<<dados[i].getOffsets()[0]<<endl<<endl;
	sort (dados.begin(),dados.end());
	for( vector<Dados<string> >::iterator it=dados.begin(); it!=dados.end(); ++it )
		cout<<*it<<endl;

}
