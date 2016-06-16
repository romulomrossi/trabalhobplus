#include<fstream>
#include<string>
#include<vector>
#include"dados.h"
#ifndef LER_ARQUIVO_H
#define LER_ARQUIVO_H
using namespace std;
vector<dados<string> > carregaArquivo(const char * fileName,int col,int chars);
#endif
