#include<iostream>
#include<list>
#include<queue>
using namespace std;


class Graph {
	int V;
	list<int> *l; // pointer to an array containing adjacency lists

public:
	 Graph(int V) {
	 	this->V = V;
	 	l = new list<int>[V]; 
	 	// It dynamically allocates a C-style array of size V, filled with list<int>
	 }

	 void addEdge(int u, int v, bool undir=true) {
	 	l[u].push_back(v);
	 	if (undir) {
	 		l[v].push_back(u);
	 	}
	}

	void bfs(int source) {
		queue<int> q;
		q.push(source);
		bool *visited = new bool[V]; // create a visited array
		visited[source] = true;

		while (!q.empty()) {
			int f = q.front();
			cout << f << " ";
			q.pop();

			for (auto i : l[f]) {
				if (!visited[i]) {
					q.push(i);
					visited[i] = true;
				}
			}	
		}
	}
};

int main() {
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(3, 5);
	g.addEdge(5, 6);
	g.addEdge(4, 5);
	g.addEdge(0, 4);
	g.addEdge(3, 4);
	g.bfs(1);
	return 0;
}