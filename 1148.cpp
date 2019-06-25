#include <iostream>
#define maxV 501
#define maxCST 999999
#define INFINITO 999999
#define Vertices int

using namespace std;

typedef struct grafo{ //crio a estrutura do grafo
    int V; //vertices
    int A; //arestas
    int adj[501][501]; //matriz pra armazenar os pontos e seus adjacentes neh
}*Grafo;

void controla(Grafo G, Vertices s, Vertices z[], double cst[], Vertices destino){
    Vertices w, w0, fr[maxV];
    for(w = 0; w < G->V; w++){
        z[w] = -1;
        cst[w]=maxCST;
    }
    fr[s]=s;
    cst[s]=0.0;

    while(1) {
        double mincst = maxCST;
        for(w=0;w<G->V;w++) {
            if(z[w] == -1 && mincst>cst[w])
                mincst=cst[w0=w];
        }
        if(mincst == maxCST){
            break;
        }
        z[w0]=fr[w0];

        for(w=0;w<G->V;w++){
            if(cst[w]>cst[w0] + G->adj[w0][w]){
                cst[w]=cst[w0] + G->adj[w0][w];
                fr[w]=w0;
            }
        }
    }
    if(cst[destino] < INFINITO)
        cout << cst[destino];
    else
        cout << "Nao e possivel entregar a carta";
    cout << "\n";
}

int main(void){
    Grafo D;
    D = new (struct grafo); //inicio meu grafo
    int i, j, cidades, acordos, consultas, origem, destino, tempo;
    Vertices z[501]; //vetor q na verdade eh so um vetor de int
    double cst[501];

    while(cin >> cidades &&  cin >> acordos){ //recebo a quantidade de cidades e acordos
        if(cidades == 0) break; //se n tenho cidades n tem pq continuar

        for(i=0;i<=cidades;i++)
            for(j=0;j<=cidades;j++)
                D->adj[i][j]=INFINITO; //para cada cidade eu coloco o valor infinito na matriz do grafo, assim iniciando minhas...cidades
        for(i=0;i<acordos;i++){
            cin >> origem; //recebo entao os acordos entre paises
            cin >> destino; //sendo a origem, destino e o tempo de envio de uma carta
            cin >> tempo;
            if(D->adj[destino][origem]!=INFINITO){ //se o destino e a origem forem diferentes de infinito na matriz, significa q nessa posicao n tem cidade
                D->adj[origem][destino]=0; //logo dou valor de 0 pq...n tem cidade aqui e atualiza o meu grafo
                D->adj[destino][origem]=0;
            } else
                D->adj[origem][destino]=tempo; //se for infinito, significa q tem a bendita cidade e posso armazenar o tempo que levara pro envio
        }
        D->V=cidades+1; //defino q minhas vertices sao as cidades
        D->A=acordos; //e que as arestas sao os acordos, pela quantidade claro

        cin >> consultas; //recebo a quantidade de consultas que vou fazer para verificar o tempo minimo de envio entre duas cidades

        for(i=0;i<consultas;i++){
            cin >> origem; //entro com a origem e o destino
            cin >> destino;
            controla(D, origem, z, cst, destino); // aqui acontece o controle entre os paises e imprime se a carta foi enviada ou n, se sim, sera impresso o tempo q levou
        }
        cout << "\n";

    }
}
