#ifndef
#define NODEF_H

template<typename D>
class NodeF {
	private:
		int ordem;
		int prox;
		Node<Dados<D> > pai;
		vector<D> chaves();
		void split();
	public:
		D remover (D chave);

		Node(int ordem);
		~Node();
		static T bulkLoading(vector<Dados <D> >, int ordem);

		void inserir(D chave);

}

#include "node.hpp"

#endif
