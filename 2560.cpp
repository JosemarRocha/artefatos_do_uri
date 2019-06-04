#include <stdio.h>
#include <limits.h>
using namespace std;

int vet[200000];
int minimo[800000];
int maximo[800000];
int soma[800000];

void build(int pos, int l, int r){
	if (l == r){
		minimo[pos] = maximo[pos] = soma[pos] = vet[l];
		return;
	}
	int mid = (l + r)/2;
	build(2*pos+1, l, mid);
	build(2*pos+2, mid+1, r);
	if(minimo[2*pos+1] < minimo[2*pos+2])
		minimo[pos] = minimo[2*pos+1];
	else
		minimo[pos] = minimo[2*pos+2];
	if(maximo[2*pos+1] > maximo[2*pos+2])
		maximo[pos] = maximo[2*pos+1];
	else
		maximo[pos] = maximo[2*pos+2];
	soma[pos]= (soma[2*pos+1] + soma[2*pos+2]);
}

int search_min(int l, int r, int lq, int rq, int pos){
	if (lq <= l && rq >= r)
		return(minimo[pos]);
	if (lq > r || rq < l)
		return INT_MAX;
	int mid = (l + r)/2;
	int a = search_min(l, mid, lq, rq, 2*pos+1);
	int b = search_min(mid+1, r, lq, rq, 2*pos+2);
	if(a < b)
		return a;
	else
		return b;
}

int search_max(int l, int r, int lq, int rq, int pos){
	if (lq <= l && rq >= r)
		return(maximo[pos]);
	if (lq > r || rq < l)
		return INT_MIN;
	int mid = (l + r)/2;
	int a = search_max(l, mid, lq, rq, 2*pos+1);
	int b = search_max(mid+1, r, lq, rq, 2*pos+2);
	if(a > b)
		return a;
	else
		return b;
}

int search_soma(int l, int r, int lq, int rq, int pos){
	if (lq <= l && rq >= r)
		return(soma[pos]);
	if (lq > r || rq < l)
		return 0;
	int mid = (l + r)/2;
	int a = search_soma(l, mid, lq, rq, 2*pos+1);
	int b = search_soma(mid+1, r, lq, rq, 2*pos+2);
	return (a + b);
}

int main(){
	int n, b, i, min, max, aux_soma;
	long long int soma;
	while(scanf("%d %d",&n, &b) != EOF){
		soma = 0;
		for (i = 0; i < n; ++i){
			scanf("%d", &vet[i]);
		}
        build(0, 0, n-1);
		for (i = 0; i < (n-b+1); ++i){
			min = search_min(0,n-1,i,(b+i)-1,0);
			max = search_max(0,n-1,i,(b+i)-1,0);
			aux_soma = search_soma(0,n-1,i,(b+i)-1,0);
			soma = soma + aux_soma - min - max;
		}
		printf("%lld\n",soma);
	}
	return 0;
}
