#include <iostream>
#include <string>
#include "lerArquivo.h"

#include <stdlib.h>
#include <algorithm>

#include "nodeF.h"

//#include<quicksort>

void bulkLoading(vector<Dados<string> > dados, int ordem){
	vector<Dados<string> >::iterator atual = dados.begin();
	for( vector<Dados<string> >::iterator it=dados.begin()+1; it!=dados.end(); ++it ){
		cout<<"comparando: "<<atual->getChave()<<" e "<<it->getChave();
	 	if(*atual==*it){
			atual->addRef( it->getOffsets().back() );
			it->clearOffsets();
			cout<<"= true"<<endl;
	 	}else{
			atual = it ;
			cout<<"= false"<<endl;
	 	}
	 }
 		 for( vector<Dados<string> >::iterator it=dados.begin(); it!=dados.end(); ++it )
 		 	cout<<*it<<endl;
}

using namespace std;
int main(int argc, char ** argv){
	vector<Dados<string> > dados;
	int digitos = atol(argv[2]);

	//dados = carregaArquivo("teste.csv",atol(argv[1]),digitos==0 ? -1 : digitos);
dados = carregaArquivo("testemenor",atol(argv[1]),digitos==0 ? 1000 : digitos);

dados.pop_back();
	sort (dados.begin(),dados.end());
	for( vector<Dados<string> >::iterator it=dados.begin(); it!=dados.end(); ++it )
		cout<<*it<<endl;

		cout<<endl<<"/\\antes depois\\/ "<<endl;
		//NodeF<string> a = NodeF<string>( 3 );
	NodeF<string> :: bulkLoading (dados, 3 );
		 //for( vector<Dados<string> >::iterator it=dados.begin(); it!=dados.end(); ++it )
		 	//cout<<*it<<endl;

	return 0;
}
