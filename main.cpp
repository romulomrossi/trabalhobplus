#include <iostream>
#include <string>
#include "lerArquivo.h"

#include <stdlib.h>
#include <algorithm>

#include "node.h"

//#include<quicksort>

using namespace std;
int main(int argc, char ** argv){
	vector<Dados<string> > dados;
	int digitos = atol(argv[2]);

	//dados = carregaArquivo("teste.csv",atol(argv[1]),digitos==0 ? -1 : digitos);
dados = carregaArquivo("teste.csv",atol(argv[1]),digitos==0 ? 1000 : digitos);

dados.pop_back();
	sort (dados.begin(),dados.end());
	// for( vector<Dados<string> >::iterator it=dados.begin(); it!=dados.end(); ++it )
	// 	cout<<*it<<endl;

		// cout<<endl<<"/\\antes depois\\/ "<<endl;
		//NodeF<string> a = NodeF<string>( 3 );
	Node<string> :: bulkLoading (dados, atol(argv[3]) );
		 //for( vector<Dados<string> >::iterator it=dados.begin(); it!=dados.end(); ++it )
		 	//cout<<*it<<endl;

	return 0;
}
