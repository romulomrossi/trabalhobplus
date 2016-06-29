#ifndef NODEF_H
#define NODEF_H
//#include "node.h"
template<typename D>
class NodeF {
	private:
		NodeF(int ordem);
		int ordem;
		int prox;
		//Node<Dados<D> > pai;
		vector<D> chaves();
		void split();
	public:
		D remover (D chave);
		~NodeF();
		static void bulkLoading(vector<D >, int ordem);

		void inserir(D chave);

};

#include "node.hpp"

#endif
