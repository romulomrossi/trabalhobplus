#include"dados.h"
	template<typename T>
	void Dados<T>::addRef(T valor, int offset){

	};
	T getChave(){
		return this.chave;
	};
	std::vector<int> getOffset(){
		return this.valores;
	};	
	template<typename T>
	Dados<T>::Dados(T chave){
		this.chave = chave;
	};
	template<typename T>
	Dados<T>::~Dados(){


	};
