#ifndef Node_H
#define Node_H
#include <math.h>
template<typename D>
class Node {
	private:
		int ordem;
		Node<D> *prox;
		Node<D> *pai;
		vector<Dados<D> > chaves; //caso nodo for folha
		vector<D> valores; //caso nodo nao for folha
		vector<Node<D>* > filhos; //apenas em nodos nao folha!
		bool folha;
		static Node<D> * split(Node<D> * esq);
		static void inserePai( Node<D> *esq, Node<D> *dir);

	public:
		Node<D>(int ordem);
		~Node<D>();
		D remover (D chave);
		static void bulkLoading(vector<Dados<D> > dados, int ordem);
		void inserir(D chave);

		friend std::ostream& operator<< (std::ostream& os,const Node<D>& node){//deve ser definida aqui dentro
			os<<"Chaves:";
			if(node.folha){
			//	for(unsigned int i=0;i<node.chaves.size();i++)
				//	os<<node.chaves[i].getChave()<<',';
			}else{
				for(unsigned int i=0;i<node.valores.size();i++)
					os<<node.valores[i]	<<',';
			}
			return os;	// fonte: http://stackoverflow.com/questions/37809053/overloading-operator-in-a-template-class/37809247
		}
};
#include "node.hpp"

#endif
