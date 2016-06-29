template<typename D>
NodeF<D>::NodeF(int ordem){
	this->ordem = ordem;
	this->chaves = vector<Dados<D> >();
};

template<typename D>
NodeF<D>::~NodeF(){};
//
// template<typename D>
// NodeF<D>::D remover (D chave)(){};

//template<typename D> //,typename T>
//NodeF<D>::void inserir(D chave);
