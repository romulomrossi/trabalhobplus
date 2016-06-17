#include <iostream>
#include <string>
#include "lerArquivo.h"

#include <stdlib.h>
using namespace std;

int main(int argc, char ** argv){
	
	vector<Dados<string> > dados;
	dados = carregaArquivo("teste.csv",atol(argv[1]),atol(argv[2]));

	for(int i=0; i<dados.size(); i++)
		cout<<"chave:"<<dados[i].getChave()<<"\n offsets:"<<dados[i].getOffsets()[0]<<endl<<endl;

}
