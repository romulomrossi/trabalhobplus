#ifndef DADOS_H
#define DADOS_H
#include<vector>

template<typename T>
class dados{
	private:
		T chave;
		std::vector<int> valores;	//offset no arquivo
	public:
		void addRef(int valor);//no arquivo...
		dados();
		~dados();

};
#endif
