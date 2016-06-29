#ifndef DADOS_H
#define DADOS_H
#include<vector>
#include<ostream>

template<typename T>
class Dados{
	private:
		T chave;
		std::vector<int> valores;	//offset no arquivo
	public:
		T getChave();
		std::vector<int> getOffsets();
		void clearOffsets();
		void addRef(int offset);//no arquivo...
		Dados<T>(T chave);
		~Dados<T>();

		bool operator<(Dados<T> b);
		bool operator>(Dados<T> b);
		bool operator==(Dados<T> b);
		bool operator!=(Dados<T> b);
		friend std::ostream& operator<< (std::ostream& os,const Dados<T>& dados){//deve ser definida aqui dentro
			T chave = dados.chave;												 //ou definido o template assim operator<< <T>
			os<<chave<<"\n Offsets:\n";											 //e declarando duas vezes template da
			os<<"qnt: "<<dados.valores.size()<<"\n";
			for(unsigned int i=0;i<dados.valores.size();i++)
				os<<"  "<<dados.valores[i]<<'\n';

			return os;	// fonte: http://stackoverflow.com/questions/37809053/overloading-operator-in-a-template-class/37809247
		}
};
#include"dados.hpp"

#endif
