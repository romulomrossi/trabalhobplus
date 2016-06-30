template<typename D>
Node<D>::Node(int ordem){
	this->pai = (Node<D>*)NULL;
	this->ordem = ordem;
	this->chaves = vector<Dados<D> >();
	this->valores = vector<D>();
};

template<typename D>
Node<D>::~Node(){};

template<typename D>
void Node<D>::inserePai(D chave, Node<D> *esq, Node<D> *dir){
		if(esq->pai==(Node<D>*)NULL){
			cout<<"chegou aqui"<<endl;
			dir->pai = esq->pai = new Node<D>(this->ordem);
			esq->pai->filhos.push_back(esq);
			esq->pai->filhos.push_back(dir);
		}else{
			esq->pai->filhos.push_back(dir);
			dir->pai = esq->pai;
		}
		esq->pai->valores.push_back(chave);
}
