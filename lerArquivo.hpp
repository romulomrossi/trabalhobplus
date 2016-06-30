#include <fstream>
#include <string>
#include <vector>
#include "dados.h"

#ifndef LER_ARQUIVO_HPP
#define LER_ARQUIVO_HPP

#define LSIZE 1000
using namespace std;

template<typename D>
vector <Dados<D> > carregaArquivo(const char * fileName,const int col,const int chars){

	fstream is(fileName);
	vector<Dados<D> > dados;
	char linha[LSIZE];
	int offset;

	while(!is.eof()){
		offset = is.tellg();
		is.getline(linha, LSIZE);
		Dados<D> atual;
		if (std::is_same<D, int>::value)
			atual = readCol(linha, col);
		else if (std::is_same<D, string>::value)
			atual = readCol(linha, col, chars);
		atual.addRef(offset);
		dados.push_back(*atual);
	}

	is.close();

	return dados;

}

template<typename D>
Dados<D> readCol(const char *str,const int col){
	std::string text = readCol(str,col,100);
	int val;
	 std::istringstream convert(text);
	 if ( !(convert >> val) )
		val = 0;
	Dados<D> ret= Dados<D>(val);
	return ret;
}

template<typename D>
Dados<D> readCol(const char *str,const int col,const int chars){
	int flag = 0;
	int j;
	char ret[chars+1];
	for(int i=0; flag<col+1 && str[i]!='\n'  ; i++){
		if(flag==col){
			for(j=0; str[j+i]!=',' && ret[j+i]!='\n' && j< chars; j++){
				ret[j] = str[j+i];
			}
			ret[j] = '\0';
			break;
		}
		if(str[i]==',')
			flag++;
	}
	string s = ret;
	Dados<D> ret = Dados<D>(s);
	return ;
}
#endif
