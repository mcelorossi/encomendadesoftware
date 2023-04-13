#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void menu_controle_caixa();
void modulo_controle_caixa();
void realizar_venda();
void atualizar_estoque();
void fechar_movimento_dia();

float total_vendas=0;


void menu_controle_caixa() {
	
	cout << "\n-----------------------------------";
	cout << "\n Modulo de Controle de Caixa!";
	cout << "\n-----------------------------------";
	cout << "\n[1] Realizar venda";
	cout << "\n[2] Atualizar estoque";
	cout << "\n[3] Fechar movimento do dia";
	cout << "\n[4] Voltar" << endl << endl;
}


void modulo_controle_caixa() {
	
	menu_controle_caixa();
	
	int opcao;
	cin >> opcao;
	
	system("cls");
	
	while (opcao != 4) {
		
		switch (opcao) {
			case 1:
				realizar_venda();
				break;
				
			case 2:
				atualizar_estoque();
				break;
				
			case 3:
				fechar_movimento_dia();
				break;
		}
		
		system("pause");
		system("cls");
		
		menu_controle_caixa();
		cin >> opcao;
		
		system("cls");
	}
}




void realizar_venda() {
	
	FILE *arquivo, *temporario;
	arquivo = fopen("Cadastro_Produtos.txt", "r+");
	temporario = fopen("temp.txt", "w");
	
	PRODUTO produto;
	string nome;
	int quantidade;
	
	cout << "Nome do produto: ";
	cin >> nome;
	
	
	if (ferror(arquivo)) {
		cout << "\nErro ao abrir o arquivo!" << endl;
	} else {
		
		if (ferror(temporario)) {
			cout << "\nErro ao abrir o arquivo temporario!" << endl;
		} else {
			
			while (fread(&produto, sizeof(PRODUTO), 1, arquivo) == 1) {
		
				if (nome == produto.nome) {
					
					cout << "Quantidade: ";					
					cin >> quantidade;
					
					if ((produto.qtd_estoque - quantidade) < 0) {
						
						cout << "\nProduto sem estoque!" << endl;
						cout << "Quantidade restante: " << produto.qtd_estoque <<endl;
					} else {
						
						cout << "\nCompra realizada com sucesso!" << endl;
						cout << "Quantidade restante: " << produto.qtd_estoque <<endl;
						produto.qtd_estoque -=  quantidade;
						total_vendas += (quantidade * produto.preco);
						
					}
					
					fwrite(&produto, sizeof(PRODUTO), 1, temporario);
				} else {
					fwrite(&produto, sizeof(PRODUTO), 1, temporario);
				}
			}
	
		}
	}	
	
	
	fclose(temporario);
	fclose(arquivo);
	
	remove("Cadastro_Produtos.txt");
	rename("temp.txt", "Cadastro_Produtos.txt");
}


void atualizar_estoque() {
	
	FILE *arquivo, *temporario;
	arquivo = fopen("Cadastro_Produtos.txt", "r+");
	temporario = fopen("temp.txt", "w");
	
	PRODUTO produto;
	int codigo;
	
	cout << "Codigo: ";
	cin >> codigo;
	
	
	if (ferror(arquivo)) {
		cout << "\nErro ao abrir o arquivo!" << endl;
	} else {
		
		if (ferror(temporario)) {
			cout << "\nErro ao abrir o arquivo temporario!" << endl;
		} else {
			
			while (fread(&produto, sizeof(PRODUTO), 1, arquivo) == 1) {
		
				if (codigo == produto.codigo) {
					
					cout << "Nova quantidade: ";
					cin >> produto.qtd_estoque;
			
					fwrite(&produto, sizeof(PRODUTO), 1, temporario);
				} else {
					fwrite(&produto, sizeof(PRODUTO), 1, temporario);
				}
			}
	
		}
	}	
	
	
	fclose(temporario);
	fclose(arquivo);
	
	remove("Cadastro_Produtos.txt");
	rename("temp.txt", "Cadastro_Produtos.txt");
	
}



void fechar_movimento_dia() {
	
	cout << "Valor total de vendas do dia: R$" << total_vendas << endl << endl;
	
}



