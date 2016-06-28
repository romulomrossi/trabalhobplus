#ifndef
#define NODE_h
template<typename D> //,typename T>
class Node {
	private:
		int ordem;
		Node<D> pai;
		vector<D> chaves();
		vector<Node<D> > filhos();
		void split();
	public:
		D remover (D chave);

		Node(int ordem);
		~Node();

		void inserir(D chave);

}

#include "node.hpp"

#endif
