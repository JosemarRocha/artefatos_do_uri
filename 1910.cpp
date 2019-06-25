#include <iostream>
#include <list>
#include<queue>

#define MAX 100001
using namespace std;
int O, D, K;
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
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
bool Graph::proibido(int v) {
	for (int i = 0; i < K; i++) {
		if (v == proibidos[i]) {
			return true;
		}
	}
	return false;
}

void Graph::addEdge(int v, int w)
{
	if (w < 1 || w > 100000)
		return;
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	int * dist = new int[V];
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++) {
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
		if (dist[D] != -1) break;
		u = queue.front();
		queue.pop();
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			if (!visited[*i] && dist[*i] == -1 && !proibido(*i))
			{
				visited[*i] = true;
				dist[*i] = dist[u] + 1;
				queue.push(*i);
			}
		}
	}
	cout << dist[D] << endl;
}
int main()
{
	Graph g(MAX);
	int i;
	for (i = 1; i < MAX; i++) {
		g.addEdge(i, i * 3);
		g.addEdge(i, i * 2);
		g.addEdge(i, i + 1);
		if (i % 2 == 0) g.addEdge(i, i / 2);
		g.addEdge(i, i - 1);
	}
	while (1) {
		cin >> O >> D >> K;
		if (O == 0 && D == 0 && K == 0)
			break;
		proibidos = new int[K];
		for (i = 0; i < K; i++)
			cin >> proibidos[i];
		g.BFS(O);
	}
	system("pause");
	return 0;
}
