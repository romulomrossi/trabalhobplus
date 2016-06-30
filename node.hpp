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
Node<D> * Node<D>::split (Node<D> * esq){
	Node<D> * dir = new Node<D>(this->ordem);
	unsigned int tam = (this->ordem-1) / 2;
	while(esq->valores.size() >= tam ){
		dir->valores.push_back(esq->valores[tam]);
	  esq->valores.erase(esq->valores.begin()+tam);
	}
	return dir;
}

template<typename D>
void Node<D>::inserePai(Node<D> *esq, Node<D> *dir){
		if(esq->pai==(Node<D>*)NULL){
			cerr<<"\nchegou aqui:";
			dir->pai = esq->pai = new Node<D>(this->ordem);
			esq->pai->filhos.push_back(esq);
			esq->pai->filhos.push_back(dir);
		}else{
			cout<<"+";
			esq->pai->filhos.push_back(dir);
			dir->pai = esq->pai;
		}
		esq->pai->valores.push_back(dir->chaves[0].getChave());
		if(pai->valores.size() >= (unsigned int) (ordem-1)/2)
			inserePai(esq->pai, split(esq->pai));

}
