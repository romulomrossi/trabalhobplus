#ifndef NODEF_H
#define NODEF_H
//#include "node.h"

template<typename D>
class NodeF {
private:
	int ordem;
	int prox;
	//Node<Dados<D> > pai;
	vector<D> chaves();
	void split();
public:
	NodeF<D>(int ordem);
	~NodeF<D>();
	D remover (D chave);
//	static void bulkLoading(vector<Dados<string> > dados, int ordem);
	void inserir(D chave);

	static void bulkLoading(vector<Dados<string> > dados, int ordem){
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
	};
};

// template<typename D>
//void bulkLoading(vector<Dados<string> > dados, int ordem);
#include "node.hpp"

#endif
