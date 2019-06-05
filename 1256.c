#include <stdio.h>
#include <stdlib.h>

typedef struct Hash {
    int n;
    struct Hash * next;
} hash;
int mod(int a, int b) {
    return a%b;
}
void insere(hash *h[], int hk, int k){
    hash* novo = (hash*)malloc(sizeof(hash*));// cria um nodo para k
    novo->n = k;
    if(h[hk]== NULL){
        h[hk] = novo;// se a posição hk estiver vazia, então ela recebe o nodo
    }
    else{ // caso contrario é inserido no next de hk que esteja vazio
        hash *aux = h[hk];
        while(aux->next!=NULL)
            aux = aux->next;
        aux->next = novo;
    }

    novo->next = NULL; 
}
void print_tabela(hash *h[],int m){
    int i;
    hash* aux;
    for(i=0;i<m;i++){
        printf("%d -> ", i);
        aux = h[i];
        while(aux!=NULL){
            printf("%d -> ", aux->n);
            aux = aux->next;
        }
        printf("\\");
        printf("\n");
    }
}
void tabela_hash(int m, int c) {
    int i,k,hk;// k é a chave, hk é a posicao na tabela
    hash *h[m];//tabela do tamanho de m
    inicializa(h,m);
    for(i=0;i<c;i++){
        scanf("%d",&k);//le a chave
        hk = mod(k,m);//hk recebe o modulo de k com m
        insere(h,hk,k);// insere a chave na tabela h na posicao hk
    }
    print_tabela(h,m);
}
void inicializa(hash* h[],int m){
    int i;
    for(i=0;i<m;i++){
        h[i] = NULL;
    }
}
int main(){
    int N,M, C, i;
    scanf("%d", &N);//casos de teste
    for (i = 0; i < N; i++) {
        scanf("%d %d", &M, &C);// tamanho da tabela e chaves
        tabela_hash(M,C);// iniciando inserção
        if (i != N - 1) // adaptando print pra ser aceito no uri
            printf("\n");
    }
    return 0;
}
