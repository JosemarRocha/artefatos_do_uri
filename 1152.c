#include <stdio.h>
#define TAM 200000

//ESTRUTURA DE UMA ROTA
typedef struct rt{
    int inicio, fim, tamanho;
}Rota;

//VETOR PARA RECEBER AS ROTAS
Rota vetor[TAM];

//ORDENA PRIORITARIAMENTE PELO TAMANHO EM KM DE CADA ROTA
void QuickSort (Rota * v, int inicio, int fim){
    if(inicio<fim){
        int i=inicio, j; // j = contador
        Rota pivo = v[inicio];
        for(j=inicio+1; j<=fim; j++){
            if(v[j].tamanho < pivo.tamanho){
                v[i] = v[j];
                v[j] = v[i+1];
                i++;
            }
        }
        v[i] = pivo;
        QuickSort(v, inicio, i-1);
        QuickSort(v, i+1, fim);
    }
}

int main(){
    int m, n, x, y, z;
    int i, j;
    //SCAN NO NUMERO DE VÉRTICES E ARESTAS
    while(scanf("%d %d", &m, &n) && m){
        int custo=0,reducao=0;
        int rotas[m+1]; //VETOR ROTAS IRÁ RECEBER A ROTA QUE SERA UTILIZADA EM CADA VERTICE
        //PREENCHE O VETOR COM NUMEROS DE 0 A M (NUMERO DE ARESTAS)
        for (i=0; i<m; i++){
            rotas[i] = i;
        }
        //RECEBE AS ROTAS E AS COLOCA NO VETOR
        for(i=0; i<n; i++){
            scanf("%d %d", &x, &y);
            scanf("%d", &vetor[i].tamanho);
            vetor[i].inicio = x;
            vetor[i].fim = y;
            custo += vetor[i].tamanho;
        }
        //ORDENA O VETOR COM AS ROTAS
        QuickSort(vetor, 0, n-1);

        //O LAÇO VERIFICA A ROTA COM MENOR TAMANHO APARTIR DO VÉRTICE I
        for (i=0;i<n;i++){
            if (rotas[vetor[i].inicio] != rotas[vetor[i].fim]){
                reducao += vetor[i].tamanho; //CALCULA O GASTO UTILIZANDO A ROTA I
                int aux = rotas[vetor[i].fim];
                //SALVA NO VETOR ROTAS A ROTA UTILIZADA NO CAMINHO DO ÍNDICE J
                for (j=0;j<m;j++){
                    if(rotas[j] == aux){
                        rotas[j] = rotas[vetor[i].inicio];
                    }
                }
            }
        }
        printf("%d\n", custo-reducao);
    }
}
