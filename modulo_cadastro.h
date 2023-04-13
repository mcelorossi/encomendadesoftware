#include <iostream>
#include <fstream>

using namespace std;

void modulo_cadastro();

typedef struct PRODUTO {
	
	int codigo;
	char nome[20];
	int qtd_estoque;
	float preco;
	
} PRODUTO;


void modulo_cadastro() {
	
	FILE *arquivo;
	PRODUTO produto;
	
	arquivo = fopen("Cadastro_Produtos.txt", "a+");
	
	
	if (ferror(arquivo)) {
		printf("\nErro ao abrir o arquivo!\n");
	} else {
		
		cout << "Informe o codigo do produto: ";
		cin >> produto.codigo;
	
		cout << "Informe o nome do produto: ";
		cin >> produto.nome;
    
    	cout << "Informe a quantidade do produto: ";
		cin >> produto.qtd_estoque;
		
		cout << "Informe o preco do produto: ";
		cin >> produto.preco;
		cout << endl << endl;
		
		fwrite(&produto, sizeof(PRODUTO), 1, arquivo);
	}
	

	fclose(arquivo);
	
}
