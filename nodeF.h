#ifndef NODEF_H
#define NODEF_H
//#include "node.h"

template<typename D>
class NodeF {
	private:
		int ordem;
		NodeF<D> *prox;
		//Node<Dados<D> > pai;
		vector<D> chaves;
		void split();
	public:
		NodeF<D>(int ordem);
		~NodeF<D>();
		D remover (D chave);
	//	static void bulkLoading(vector<Dados<string> > dados, int ordem);
	void inserir(D chave);

	static void bulkLoading(vector<Dados<string> > dados, int ordem){
		vector<Dados<string> >::iterator atual = dados.begin();
		NodeF<string> novo = NodeF<string>(ordem);
		NodeF<string> *aux;

		for( vector<Dados<string> >::iterator it=dados.begin()+1; it!=dados.end(); ++it ){
			//cout<<"comparando: "<<atual->getChave()<<" e "<<it->getChave();
			if(*atual==*it){
				atual->addRef( it->getOffsets().back() );
				it->clearOffsets();
				//cout<<"= true"<<endl;
			}else{
				atual = it ;
				//cout<<"= false"<<endl;
				if(novo.chaves.size()>=(ordem-1)/2){
					aux = &novo;
					novo = NodeF<string>(ordem);
					aux->prox = &novo;
				}
				unsigned int a = atual-dados.begin();
				//novo->chaves.push_back(dados[a]);
				cout<<a<<endl;
				cout<<novo.chaves[0];
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
