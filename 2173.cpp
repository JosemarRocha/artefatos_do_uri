/*
Union Find Kruskal function by Leonardo Deliyannis Constantin
https://github.com/leodeliyannis
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

//struct para as esquinas e ruas
typedef pair<int, int> ii;
//struct com as esquinas e ruas mais o gasto
typedef pair<int, ii> edge;

class Union{
private:
    vector<int> p, rank;
public:
    Union(int N){
        p.assign(N, 0);
        rank.assign(N, 0);
        for(int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i){
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) p[y] = x;
            else{
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

//kruskal junto com a Union irá juntar os vértices dependendo da ordem do vetor
int kruskal(int N, const vector<edge> &rotas){
    int custo = 0;
    Union UF(N);
    for(edge e : rotas){
        if(!UF.isSameSet(e.second.first, e.second.second)){
            UF.unionSet(e.second.first, e.second.second);
            custo += e.first;
        }
    }
    return custo;
}

int main(){
    int N, M, x, y, c, quantia;
    while(scanf("%d %d", &N, &M), N != 0){
        vector<edge> rotas; //vetor com gasto e o struct de quadra e rua
        while(M--){
            scanf("%d %d %d", &x, &y, &c);
            x--; y--; //decresce para o valor iniciar em 0 e ir até m-1
            rotas.push_back({c, {x, y}}); //adiciona no vetor ruas para asfaltar
        }
        //organiza em ordem crescente para pegar o mínimo de ruas com o menores valores
        sort(rotas.begin(), rotas.end());
        quantia = -kruskal(N, rotas);
        //organiza em ordem decrescente para pegar o mínimo de ruas com os maiores valores
        reverse(rotas.begin(), rotas.end());
        quantia += kruskal(N, rotas);
        printf("%d\n", quantia);
    }
    return 0;
}
