#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int v[100000];
int segTree[400000];

void print_sinal(int a) {
	if (a > 0) printf("+");
	else if (a < 0)printf("-");
	else printf("0");
}
int valor(int a){
    if (a > 0)
        return 1;
    else{
        if(a < 0)
            return -1;
        else
            return 0;
    }
    return 0;
}
void build_SegTree(int index, int a, int b) {
	if (a == b)
		segTree[index] = valor(v[a - 1]);
	else{
		int m = (b + a) / 2;
		build_SegTree(2 * index, a, m);
		build_SegTree(2 * index + 1, m + 1, b);

		segTree[index] = segTree[index * 2] * segTree[index * 2 + 1];
	}
}
void updateTreeNode(int index, int a, int b, int i, int x) {
	if (i > b || i < a)
		return;

	if (a == b && b == i){
        segTree[index] = valor(x);
		return;
	}

	int m = (a + b) / 2;
	updateTreeNode(2 * index, a, m, i, x);
	updateTreeNode(2 * index + 1, m + 1, b, i, x);

	segTree[index] = segTree[index * 2] * segTree[index * 2 + 1];
}
int query(int index, int a, int b, int i, int j) {
	if (i > b || j < a)
		return 1;

	if (a >= i && b <= j)
		return segTree[index];

	int m = (a + b) / 2;
	int x = query(index * 2, a, m, i, j);
	int y = query(index * 2 + 1, m + 1, b, i, j);

	return x * y;

}
int main() {
    int i,x,y,produto;
	char c[1];//comando
	int N, K;
	while (scanf("%d %d", &N, &K) != EOF) {
		for (i = 0; i < N; i++)
		scanf("%d",&v[i]);//lendo os valores iniciais da sequência
	build_SegTree(1, 1, N);
	while (0 < K--) {//K linhas de comando
		scanf("%s %d %d",&c,&x, &y);
		if (c[0] == 'C' ) updateTreeNode(1,1,N,x,y);
		else if (c[0] == 'P') {
			produto = query(1,1,N,x,y);
			print_sinal(produto);
		}
	}
		printf("\n");
	}
	return 0;
}
