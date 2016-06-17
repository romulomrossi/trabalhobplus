#include "lerArquivo.h"
#include <iostream>
#define LSIZE 1000
using namespace std;

vector <Dados<string> > carregaArquivo(const char * fileName,const int col,const int chars){
	
	fstream is(fileName);
	vector<Dados<string> > dados;
	char linha[LSIZE];
	int offset;

	while(!is.eof()){
		offset = is.tellg();
		is.getline(linha, LSIZE);
		Dados<string> atual = Dados<string>(readCol(linha, col, chars));
		atual.addRef(offset);

		cout<<"chave:"<<atual.getChave()<<"\n offsets:"<<atual.getOffsets()[0]<<endl<<endl;
//		cout<<atual.getChave()<<endl;
		//dados.insert(atual);
	}

	is.close();

	return dados;

}

string readCol(const char *str,const int col,const int chars){
	int flag = 0, j;
	char ret[chars+1];
	for(int i=0; flag<col+1 && str[i]!='\0' ; i++){
		if(flag==col){
			for(j=0; str[j+i]!=',' && ret[j+i]!='\n' && j<chars; j++){
				ret[j] = str[j+i];
			}
			ret[j] = '\0';
			break;
		}
		if(str[i]==',')
			flag++;
	}
	string s = ret;
	return s;
}


