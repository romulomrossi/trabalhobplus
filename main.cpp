#include<iostream>
#include<string>
#include"lerArquivo.h"

#include<stdlib.h>
using namespace std;
int main(int argc, char ** argv){
	
	carregaArquivo("teste.csv",atol(argv[1]),atol(argv[2]));
}
