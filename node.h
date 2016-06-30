#ifndef Node_H
#define Node_H

template<typename D>
class Node {
	private:
		int ordem;
		Node<D> *prox;
		Node<D> *pai;
		vector<Dados<D> > chaves;
		vector<D> valores;
		vector<Node<D>* > filhos;
		bool folha;
		Node<D> * split(Node<D> * esq);
		void inserePai( Node<D> *esq, Node<D> *dir);

	public:
		Node<D>(int ordem);
		~Node<D>();
		D remover (D chave);
		//	static void bulkLoading(vector<Dados<string> > dados, int ordem);
		void inserir(D chave);

	static void bulkLoading(vector<Dados<string> > dados, int ordem){
		vector<Dados<string> >::iterator atual = dados.begin();
		Node<string> *novo = new Node<string>(ordem);
		novo->folha = true;
		Node<string> *first = novo;
		Node<string> *aux;

		for( vector<Dados<string> >::iterator it=dados.begin()+1; it!=dados.end(); ++it ){
			//cout<<"comparando: "<<atual->getChave()<<" e "<<it->getChave();
			if(*atual==*it){
				atual->addRef( it->getOffsets().back() );
				it->clearOffsets();
			}else{
				unsigned int a = atual-dados.begin();
				novo->chaves.push_back(dados[a]);
				atual = it ;
				if(novo->chaves.size()>=(unsigned int)(ordem-1)/2){
					// cout<<*atual<<endl;
					aux = novo;
					novo = new Node<string>(ordem);
					novo->folha = true;
					aux->prox = novo;
				}
			}
		}

		novo->prox = (Node<string>*)NULL;
		aux->prox =  (Node<string>*)NULL;
		novo = first;
		while(novo->prox != (Node<string>*)NULL ){
			for(unsigned int i = 0; i<novo->chaves.size() && novo->folha; i++){
				 cout<<novo->chaves[i]<<endl;
				 novo->prox->inserePai( novo, novo->prox);
				 novo = novo->prox;
			}
		}

		// for( vector<Dados<string> >::iterator it=dados.begin(); it!=dados.end(); ++it )
		// 	if(!it->getOffsets().empty())
		// 		cout<<*it<<endl;
	};
};

#include "node.hpp"

#endif
