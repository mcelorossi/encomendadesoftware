#include <iostream>
#include <fstream>
#include "modulo_cadastro.h"
#include "modulo_acesso_dados.h"
#include "modulo_controle_caixa.h"
#include "modulo_delivery.h"

using namespace std;

void menu() {
	
	system("MODE con cols=168 lines=40");
	
	cout << "\n-----------------------------------------------------";
	cout << "\n Bem-vindo ao Sistema de Compras do Mercadinho!";
	cout << "\n-----------------------------------------------------";
	cout << "\n[1] Modulo de Cadastro";
	cout << "\n[2] Modulo de Acesso aos Dados";
	cout << "\n[3] Modulo de Controle de Caixa";
	cout << "\n[4] Modulo de Delivery";
	cout << "\n[5] Sair" << endl << endl;
}


int main() {
	
	int opcao;
	menu();
	cin >> opcao;
	
	system("pause");
	system("cls");
	
	while (opcao != 5) {
		
		switch (opcao) {
		
		case 1:
			modulo_cadastro();
			break;
			
		case 2:
			modulo_acesso_dados();
			break;
			
		case 3:
			modulo_controle_caixa();
			break;
			
		case 4:
			modulo_delivery();
			break;
			
		}
		
		system("pause");
		system("cls");
		
		menu();
		cin >> opcao;
		
		system("pause");
		system("cls");
	}
	
}

