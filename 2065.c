#include <stdio.h>
#include <stdlib.h>
void FilaSupermercado(int n, int m){
    int f[n],t[n],c[m],a[n],i,d;
    for(i=0;i<n;i++){
        scanf("%d",&f[i]);// é o tempo de cada funcionário para processar um item
    }
    for(i=0;i<m;i++){
        scanf("%d",&c[i]); // quantos itens tem cada cliente;
    }
    for(i=0;i<n;i++){
        t[i] = 0; // tempo de todo os clientes atendidos por cada caixa
        a[i] = 0;//tempo para um cliente ser atendido em cada caixa
    }
    int maior = t[0]; // o tempo total para atender todos os clientes da fila
    for(i=0,d = n;i<m;d++){
        if(d==n) d = 0; // d é um contador para o funcionário que vai atender,sabendo que a prioridade de atendimento é do menor para o maior
        if(a[d] == 0){// quando um caixa esta livre
            a[d] += c[i]*f[d]; // 'a' recebe o tempo para processar todos os itens do cliente
            t[d] += a[d];//este tempo é adicionado ao tempo total do caixa
            i++; // i é o contador para o cliente que vai até m
        }
        a[d]--; // o tempo em que o funcionário esta atendendo um cliente decrementa, ate chegar a zero significa que este está livre
        if(maior<t[d]) maior = t[d]; //atualiza com o tempo do funcionário com  maior tempo de atendimento
    }
    printf("%d\n",maior);
}
int main (){
    int N,M;// funcionario e cliente
    scanf("%d %d",&N,&M);
    FilaSupermercado(N,M);
    return 0;
}
