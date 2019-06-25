#include <iostream>
#include <list>
#include <queue>
#define M 26
#define D 25

using namespace std;

int matrix[5][5];
int *proibidos;
class Graph
{
	int V;    // No. of vertices
	list<int> *adj;
	bool proibido(int v);
public:
	Graph(int V);  // Constructor
	void addEdge(int v, int w);
	void BFS(int s);
    //void printGraph();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
bool Graph::proibido(int v) {
	for (int i = 0; i < M; i++) {
		if (v == proibidos[i]) {
			return true;
		}
	}
	return false;
}

void Graph::addEdge(int v, int w)
{
    if(w > 0 && w < M)	
        adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	int * dist = new int[V];
	bool *visited = new bool[V];
	for (int i = 0; i < M; i++) {
		visited[i] = false;
		dist[i] = -1;
	}
	queue<int> queue;

	visited[s] = true;
	dist[s] = 0;
	queue.push(s);

	int u;
	list<int>::iterator i;

	while (!queue.empty())
	{
		u = queue.front();
		queue.pop();
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			if (!visited[*i] && dist[*i] == -1 && !proibido(*i))
			{
				visited[*i] = true;
				dist[*i] = dist[u] + 1;
				queue.push(*i);
                //cout << *i << endl;
			}
		}
	}
    if (dist[D] == -1) cout << "ROBBERS" << endl;
    else cout << "COPS" << endl;
}
/*void Graph::printGraph() 
{ 
    for (int v = 0; v < M; ++v) 
    { 
        cout << "\n Adjacency list of vertex "
             << v << "\n head "; 
        for (auto x : adj[v]) 
           cout << "-> " << x; 
        printf("\n"); 
    } 
}*/
int main(){
    int T;
    int i,j;
    int k = 1;
    Graph g(M);
        g.addEdge(0,1);
    while (k < M){
        if(k%5!=0) g.addEdge(k, k + 1);
        if((k-1)%5!=0)g.addEdge(k, k - 1);
        g.addEdge(k, k + 5);
        g.addEdge(k, k - 5);
        k++;
    }
    //g.printGraph();
    cin >> T;
    while( T > 0){
        for(i = 0; i < 5; i++){
            for(j = 0; j < 5; j++){
                cin >> matrix[i][j];
            }
        }
        proibidos = new int[M];
		for (i = 0; i < M; i++)
            proibidos[i] = 0;
         for(i = 0,k = 1; i < 5; i++){
             for(j = 0; j < 5; j++, k++){
                if(matrix[i][j] == 1){
                    proibidos[k] = k;
                    //cout << "proibindo" << k << endl;
                }
            }
        }
        g.BFS(0);
        T--;
    }
    return 0;
}
