
NodeF<D>::Node(int ordem){
	this->ordem = ordem;
}
template<typename D>
NodeF<D>::D remover (D chave);
~Node();

template<typename D>
NodeF::static void bulkLoading(vector<Dados<D> > &dados, int ordem){
	vector<D>::iterator atual = dados.begin();
	for( vector<D>::iterator it=dados.begin()+1; it!=dados.end(); ++it ){
		cout<<"comparando: "<<atual->getChave()<<" e "<<it->getChave();
	 	if(*atual==*it){
			atual->addRef( it->getOffsets().back() );
			it->clearOffsets();
			cout<<"= true"<<endl;
	 	}else{
			atual = it ;
			cout<<"= false"<<endl;
	 	}
	 }

}
//template<typename D> //,typename T>
//NodeF<D>::void inserir(D chave);
