#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define BIG 9999
#define TAM 17

int **AlocaMDist(int n);
int **LerMatriz(int **M, int n);
void MostrarResultado(int n, int ini, float dist[TAM], float pred[TAM], int fim);
void ImprimeMatriz(int **M, int n);
void Dijkstra(int **G, int n, int inicial, int fim);
void modulo_delivery();


using namespace std;

int **AlocaMDist(int n) {
	
	int i;
    int **Md;
    
    Md = (int**) malloc(n*sizeof(int*));
    
    for (i=0; i<n; i++) {
    	
    	Md[i] = (int*) malloc(n*sizeof(int));
	}
	
	return Md;
}


int **LerMatriz(int **M, int n) {
	
	int i, j;
	
	FILE *ArqM;
	
	ArqM = fopen("Gr17.txt", "r");
	
	if(ArqM == NULL) {
		cout << "Arquivo inexistente ou com problema!" << endl;
		return 0;
	}
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			fscanf(ArqM, "%d", &M[i][j]);
		}
	}
	
	fclose(ArqM);
	return M;
}


void MostrarResultado(int n, int ini, float dist[TAM], float pred[TAM], int fim) {
	
	int i, k, ind, j, rota[TAM];
	
	for(i=0;i<n;i++) {
		
		int k, ind=0;
		if((i!=ini)&&(i==fim)) {
			
			cout << "\nMenor distancia do vertice " << ini << " ao vertice " <<i<< " = " << dist[i] << endl;
            cout << "Melhor Rota: ";
            rota[ind] = i;
            j = i;
            
            do {
            	
            	j=pred[j];
                ind++;
                rota[ind]=j;
			} while (j!=ini);
			
			while(ind>=0) {
				
				if(ind!=0) {
					cout << rota[ind] << " -> ";
				} else {
					cout << rota[ind];
				}
				
				ind--;
			}
		}
	}
}


void ImprimeMatriz(int **M,int n) {
	
	int i, j;
	
	for(i=0;i < n; i++) {
		cout << "|";
		for (j=0; j < n; j++) {
			
			if(j>0){
				cout << "\t" << M[i][j];
			} else {
				
				cout<<M[i][j];
			}
		}
		cout << "|" << endl;
	}
}


void Dijkstra(int **G,int n,int inicial,int fim) {
	
	float custo[n][n], distancia[n], pred[n];
    int visitado[n], cont, distanciamin, proxno, i, j;
    int caminho[n];
    
    for(i=0;i<n;i++) {
    	for(j=0;j<n;j++) {
    		
    		custo[i][j]=G[i][j];
		}
	}
	
	for(i=0;i<n;i++) {
		distancia[i]=custo[inicial][i];
        pred[i]=inicial;
        visitado[i]=0;
	}
	
	distancia[inicial] = 0;
    visitado[inicial] = 1;
    cont = 1;
    
    while(cont<n-1) {
    	
    	distanciamin = BIG;
    	
    	for(i=0;i<n;i++) {
    		if(distancia[i] < distanciamin && !visitado[i]) {
    			distanciamin = distancia[i];
                proxno = i;
			}
		}
		
		visitado[proxno] = 1;
		
		for(i=0;i<n;i++) {
			if(!visitado[i]) {
				
				if(distanciamin + custo[proxno][i] < distancia[i]) {
					distancia[i] = distanciamin+custo[proxno][i];
                    pred[i] = proxno;
				}
			}
		}
		
		cont++;
	}
	
	MostrarResultado(n, inicial, distancia, pred, fim);
}



void modulo_delivery() {
	
	int inicio, fim;
    int **MDist;
    
    MDist = AlocaMDist(TAM);
    MDist = LerMatriz(MDist, TAM);
    
    ImprimeMatriz(MDist, TAM);
    
    cout << "\n\nInforme o Vertice Inicial: ";
    cin >> inicio;
    
    cout << "Informe o Vertice Final: ";
    cin >> fim;
    
    Dijkstra(MDist, TAM, inicio, fim);
    cout << endl;
    
    free(MDist);
}
