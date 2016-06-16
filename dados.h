#ifndef DADOS_H
#define DADOS_H
#include<vector>

template<typename T>
class Dados{
	private:
		T chave;
		std::vector<int> valores;	//offset no arquivo
	public:
		void addRef(int valor);//no arquivo...
		Dados();
		~Dados();

};
#endif
