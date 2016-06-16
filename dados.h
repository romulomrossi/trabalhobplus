#ifndef DADOS_H
#define DADOS_H
#include<vector>

template<typename T>
class Dados{
	private:
		T chave;
		std::vector<int> valores;	//offset no arquivo
	public:
		T getChave();
		std::vector<int> getOffset();
		void addRef(int offset);//no arquivo...
		Dados<T>(T chave);
		~Dados();

};
#endif
