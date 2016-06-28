
Node<D>::Node(int ordem){
		this->ordem = ordem;
}
template<typename D>
Node<D>::D remover (D chave);
~Node();

template<typename D>
static T bulkLoading(vector<Dados<D> > dados, int ordem){
	NodeF<D> nodeAtual(ordem);
	Dados<D> *atual = dados.erase(dados.begin());
	for( vector<D>::iterator it=dados.begin()+1; it!=dados.end(); ++it ){
		if(*atual==*it){
			atual->addRef(it->getOffsets().pop_back() );
			~it();
		}else{
			atual=it;
		}
	}

}
template<typename D> //,typename T>
Node<D>::void inserir(D chave);
