#include"lerArquivo.h"
#include<iostream>
#define LSIZE 1000
using namespace std;
vector<dados<string> > carregaArquivo(const char * fileName,int col,int chars){
	fstream is(fileName);

	string linha;

	while(!is.eof()){
		getline(is, linha);
		cout<<linha<<endl;
	}
	is.close();

	vector<dados<string> > o;
	return o;
}
