#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void modulo_acesso_dados();
void menu_acesso_dados();
void consulta();
void listagem();
void edicao();
void exclusao();

void menu_acesso_dados() {
	
	cout << "\n-----------------------------------";
	cout << "\n Modulo de Acesso aos Dados!";
	cout << "\n-----------------------------------";
	cout << "\n[1] Consulta";
	cout << "\n[2] Listagem";
	cout << "\n[3] Edicao";
	cout << "\n[4] Exclusao";
	cout << "\n[5] Voltar" << endl << endl;
}
	

void modulo_acesso_dados() {
	
	menu_acesso_dados();
	
	int opcao;
	cin >> opcao;
	
	system("cls");
	
	while (opcao != 5) {
		
		switch (opcao) {
			case 1:
				consulta();
				break;
				
			case 2:
				listagem();
				break;
				
			case 3:
				edicao();
				break;
				
			case 4:
				exclusao();
				break;
		}
		
		system("pause");
		system("cls");
		
		menu_acesso_dados();
		cin >> opcao;
		
		system("cls");
	}
}



void consulta() {
	
	FILE *arquivo;
	arquivo = fopen("Cadastro_Produtos.txt", "r");
	
	PRODUTO produto;
	int codigo;
	
	cout << "Codigo: ";
	cin >> codigo;
	
	system("cls");
	
	while (fread(&produto, sizeof(PRODUTO), 1, arquivo) == 1) {
		
		if (codigo == produto.codigo) {
			cout << "Codigo: " << produto.codigo << endl;
			cout << "Nome: " << produto.nome << endl;
			cout << "Quantidade: " << produto.qtd_estoque << endl;
			cout << "Preco: " << produto.preco << endl << endl << endl;
		}
	}
	
	fclose(arquivo);
}


void listagem() {
	
	FILE *arquivo;
	arquivo = fopen("Cadastro_Produtos.txt", "r");
	
	PRODUTO produto;
	
	while (fread(&produto, sizeof(struct PRODUTO), 1, arquivo) == 1) {
		
		cout << "Codigo: " << produto.codigo << endl;
		cout << "Nome: " << produto.nome << endl;
		cout << "Quantidade: " << produto.qtd_estoque << endl;
		cout << "Preco: " << produto.preco << endl << endl << endl;
	}
	
	fclose(arquivo);
}


void edicao() {
	
	FILE *arquivo, *temporario;
	arquivo = fopen("Cadastro_Produtos.txt", "r+");
	temporario = fopen("temp.txt", "w");
	
	PRODUTO produto;
	int codigo;
	
	cout << "Codigo: ";
	cin >> codigo;
	
	system("cls");
	
	if (ferror(arquivo)) {
		cout << "\nErro ao abrir o arquivo!" << endl;
	} else {
		
		if (ferror(temporario)) {
			cout << "\nErro ao abrir o arquivo temporario!" << endl;
		} else {
			
			while (fread(&produto, sizeof(PRODUTO), 1, arquivo) == 1) {
		
				if (codigo == produto.codigo) {
					cout << "Nome: ";
					cin >> produto.nome;
					
					cout << "Quantidade: ";
					cin >> produto.qtd_estoque;
					
					cout << "Preco: ";
					cin >> produto.preco;
					
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






void exclusao() {
	
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
		
				if (codigo != produto.codigo) {
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


