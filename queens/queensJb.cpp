#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdio>

#define MAX 18

using namespace std;



// guarda a linha que cada rainha ocupa na coluna de 0-7
int linhas[MAX];
long int count = 0;

void imprimeTab(int *linhas){
	for (int i = 0; i < MAX; ++i)
		printf("%i ", linhas[i]);
	printf("\n");
}

bool valido(int lin, int col){
	// verifica se a rainha a ser colocada nao conflita com as que ja existem
	for (int rp = 0; rp < col; rp++)
		if (linhas[rp] == lin || (abs(linhas[rp]-lin) == abs(rp-col)))
			return false;
	return true;

}


void backtracking(int c){
	if (c == MAX){ // passei por todas as colunas..
		count++;
		//imprimeTab(linhas);
	} else {
		//para todas as linhas
		for (int lin = 0; lin < MAX; lin++)
			if (valido(lin, c)){
				linhas[c] = lin;
				backtracking(c+1);
			}
	}
}

int main(int argc, char const *argv[])
{

	memset(linhas, 0, sizeof linhas);
	backtracking(0);
	printf("Existem %ld caminhos possíveis \n", count);
	return 0;
}