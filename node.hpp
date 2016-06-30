template<typename D>
Node<D>::Node(int ordem){
	this->pai = (Node<D>*) NULL;
	this->ordem = ordem;
	this->chaves = vector<Dados<D> >();
};

template<typename D>
Node<D>::~Node(){};

template<typename D>
Node<D>::void inserePai(D chave, Node<D> *esq, Node<D> *dir){
		if(esq->pai==NULL){
			dir->pai = esq->pai = new Node<D>(this->ordem);
			esq->pai->filhos.push_back(esq);
			esq->pai->filhos.push_back(dir);
		}else{
			esq->pai->filhos.push_back(dir);
			dir->pai = esq->pai;
		}
		esq->pai->chaves.push_back(chave);
}
