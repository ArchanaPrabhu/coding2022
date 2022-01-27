#include<iostream>
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

	void dfsHelper(int source, bool *visited) {

		visited[source] = true;
		cout << source << "--"; 
		for (int i : l[source]) {
			if (!visited[i]) {
				dfsHelper(i, visited);
			}
		}
		return;
	}

	void dfs(int source) {
		bool *visited = new bool[V]{0};
		dfsHelper(source, visited);
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
	g.dfs(1);
	return 0;
}