#include <iostream>
#include <cstdio>

using namespace std;

int grafo[49][49];
int feito[49];
int count = 0;

int dfs(int ver, int v){ //depth first search
    int i, count = 0;
    feito[ver] = true;

    for(i=0; i<v; i++){
        if(grafo[ver][i] && !feito[i]){
            count += dfs(i,v)+1;
        }
    }
    return count;
}

int main()
{
    int t, n, v, a;
    int i, j, x, y;

    scanf("%d", &t);//numero de casos
    while(t--){
        scanf("%d", &n); //ponto inicial do meu grafo
        scanf("%d %d", &v, &a); //numero de vertices e arestas

        for(i=0; i<v; i++){
            for(j=0;j<v;j++){
                grafo[i][j]=0; //enchendo o grafo com 0
            }
            feito[i] = false; //colocando falsos no meu vetor de caminhos feitos
        }
        while(a--){ //a pq o problema descreve q a quantidade de linhas a seguir deve vir da quantidade de arestas definidas
            scanf("%d %d", &x, &y); //informo a linha q quero desenhar entre um ponto e outro
            grafo[x][y]=1;//aqui eu estou informando que aquele caminho existe
            grafo[y][x]=1;
        }
        printf("%d\n", dfs(n,v)*2); //imprimo a quantidade minima de movimentos para se desenhar o labirinto
    }
    return 0;
}
