#include<fstream>
#include<string>
#include<vector>
#include"dados.h"
#ifndef LER_ARQUIVO_H
#define LER_ARQUIVO_H
using namespace std;
vector<Dados<string> > carregaArquivo(const char * fileName,int col,int chars);
string readCol(const char *str, int col, int chars);
#endif

