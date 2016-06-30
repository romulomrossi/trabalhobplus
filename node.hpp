template<typename D>
Node<D>::Node(int ordem){
	this->pai = (Node<D>*)NULL;
	this->ordem = ordem;
	this->chaves = vector<Dados<D> >();
	this->valores = vector<D>();
	this->folha = false;
};

template<typename D>
Node<D>::~Node(){};

template<typename D>
Node<D> * Node<D>::split (Node<D> * esq){
	Node<D> * dir = new Node<D>(esq->ordem);
	unsigned int tam = floor ( (esq->ordem-1) / 2 );
	cout<<"uhmmm: ";
	while(esq->valores.size() > tam ){
		dir->valores.push_back(esq->valores[tam]);
	  esq->valores.erase(esq->valores.begin()+tam);
	}
	cerr<<"\nesquerda: ";
	for(unsigned int i = 0; i < esq->valores.size();i++)
			cerr<<esq->valores[i]<<',';
	cerr<<"\ndireita: ";
	for(unsigned int i = 0; i < dir->valores.size();i++)
			cerr<<dir->valores[i]<<',';
	cerr<<"\n";
	return dir;
}

template<typename D>
void Node<D>::inserePai(Node<D> *esq, Node<D> *dir){
		if(esq->pai==(Node<D>*)NULL){
			cerr<<"chegou aqui:";
			esq->pai = new Node<D>(esq->ordem);
			dir->pai = esq->pai;
			esq->pai->filhos.push_back(esq);
			esq->pai->filhos.push_back(dir);
			cerr<<"né!";
		}else{
			cerr<<"+";
			esq->pai->filhos.push_back(dir);
			dir->pai = esq->pai;
		}
		if(dir->folha)
			esq->pai->valores.push_back(dir->chaves[0].getChave());
		else
			esq->pai->valores.push_back(dir->valores[0]);
		if(esq->pai->valores.size() > (unsigned int) (esq->ordem-1) ){
			cerr<<"\ncarregado: "<<esq->pai->valores.size()<<" elementos, hora de splitar!\n";
			cerr<< *(esq->pai) <<"\n";
			Node<D>::inserePai(esq->pai, split(esq->pai));
		}

}

template<typename D>
void Node<D>:: bulkLoading(vector<Dados<D> > dados, int ordem){
	typename vector<Dados<D> >::iterator atual = dados.begin();
	Node<D> *novo = new Node<D>(ordem);
	novo->folha = true;
	Node<D> *first = novo;
	Node<D> *aux;

	for(typename vector<Dados<D> >::iterator it=dados.begin()+1; it!=dados.end(); ++it ){
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
				novo = new Node<D>(ordem);
				novo->folha = true;
				aux->prox = novo;
			}
		}
	}

	novo->prox = (Node<D>*)NULL;
	aux->prox =  (Node<D>*)NULL;
	novo = first;
	while(novo->prox != (Node<D>*)NULL ){
		for(unsigned int i = 0; i<novo->chaves.size() && novo->folha; i++){
			 cout<<novo->chaves[i]<<endl;
			 Node<D>::inserePai( novo, novo->prox);
			 novo = novo->prox;
		}
	}

	// for( vector<Dados<D> >::iterator it=dados.begin(); it!=dados.end(); ++it )
	// 	if(!it->getOffsets().empty())
	// 		cout<<*it<<endl;
};
