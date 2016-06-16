#include"dados.h"
	
	template<typename T>
	void Dados<T>::addRef(int offset){
		this.valores.insert(offset);
	};
	template<typename T>
	T Dados<T>::getChave(){
		return this.chave;
	};
	template<typename T>
	std::vector<int> Dados<T>::getOffset(){
		return this.valores;
	};	
	template<typename T>
	Dados<T>::Dados(T chave){
		this.chave = chave;
	};
	template<typename T>
	Dados<T>::~Dados(){


	};
