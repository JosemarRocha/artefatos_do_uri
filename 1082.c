#include <stdio.h>
#include <limits.h>
#include <string.h>
#define BRANCO 0
#define CINZA 1
#define PRETO 2
typedef struct grafo {
	char v[1];
	struct grafo* adj[25];
	int n_e, cor;
} Grafo;
typedef struct componentes {
	int comp[26];
	int n_vertice;
} Componentes;
void inicializa(Grafo* G[], Componentes* c[]) {
	int i, l, j;
	for (i = 0, l = 97; i < 26; i++, l++) {
		G[i] = (Grafo*)malloc(sizeof(Grafo));
		c[i] = (Componentes*)malloc(sizeof(Componentes));
		c[i]->n_vertice = 0;
		G[i]->v[0] = l;
		G[i]->n_e = 0;
		G[i]->cor = BRANCO;
		for (j = 0; j < 25; j++) {
			G[i]->adj[j] = NULL;
		}
	}
}
void reinicializa(Grafo* G[], Componentes* c[]) {
	int i, j;
	for (i = 0; i < 26; i++) {
		c[i]->n_vertice = 0;
		G[i]->n_e = 0;
		G[i]->cor = BRANCO;
		for (j = 0; G[i]->adj[j] < 25; j++) {
			G[i]->adj[j] = NULL;
		}
	}
}
void BFS_comp_visit(Grafo* G, Componentes* C) {
	C->comp[C->n_vertice] = G->v[0];
	C->n_vertice++;
	G->cor = CINZA;
	int k;
	for (k = 0; k < G->n_e; k++) {
		if (G->adj[k] != NULL && G->adj[k]->cor == BRANCO)
			BFS_comp_visit(G->adj[k], C);
	}G->cor = PRETO;
}
void encerra(Grafo* G[], Componentes* c[]) {
	int i;
	for (i = 0; i < 26; i++) {
		free(G[i]);
		free(c[i]);
	}
}
int main() {
	int N, V, E, i, j, k, n, t;
	char a[1], b[1];
	Grafo* G[26];
	Componentes* C[26];
	inicializa(G, C);
	scanf("%d", &N);
	n = N;
	while (0 < N--) {
		scanf("%d %d", &V, &E);
		for (i = 0; i < E; i++) {
			setbuf(stdin, NULL);
			scanf("%c %c", a, b);
			//int A = a[0] - 97; int B = b[0] - 97;
			//G[A]->adj[G[A]->n_e++] = G[B];
			//G[B]->adj[G[B]->n_e++] = G[A];
			for (j = 0; j < V; j++) {
				if (a[0] == G[j]->v[0]) {
					for (k = 0; k < V; k++) {
						if (b[0] == G[k]->v[0]) {
							G[j]->adj[G[j]->n_e++] = G[k];
							G[k]->adj[G[k]->n_e++] = G[j];
							break;
						}
					}
				}
			}

		}
		t = 0;
		for (i = 0, j = 0; i < V; i++) {
			if (G[i]->cor == BRANCO) {
				BFS_comp_visit(G[i], C[j]);
				int m, x, y;
				for (x = 0; x < C[j]->n_vertice - 1; x++) {
					for (y = x + 1; y < C[j]->n_vertice; y++) {
						if (C[j]->comp[x] > C[j]->comp[y]) {
							m = C[j]->comp[x];
							C[j]->comp[x] = C[j]->comp[y];
							C[j]->comp[y] = m;
						}
					}
				}
				j++; t++;
			}
		}
		printf("Case #%d:\n", n - N);
		for (i = 0; i < t; i++) {
			for (j = 0; j < C[i]->n_vertice; j++)
				printf("%c,", C[i]->comp[j]);
			printf("\n");
		}
		printf("%d connected components\n\n", t);
		reinicializa(G, C);
	}
	encerra(G, C);
	system("pause");
	return 0;
}
