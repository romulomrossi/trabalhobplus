#ifndef DADOS_HPP
#define DADOS_HPP
	
	template<typename T>
	void Dados<T>::addRef(int offset){
		valores.push_back(offset);
	};
	template<typename T>
	T Dados<T>::getChave(){
		return this->chave;
	};
	template<typename T>
	std::vector<int> Dados<T>::getOffsets(){
		return this->valores;
	};	
	template<typename T>
	Dados<T>::Dados(T chave){
		this->chave = chave;
	};
	template<typename T>
	Dados<T>::~Dados(){


	};

#endif
