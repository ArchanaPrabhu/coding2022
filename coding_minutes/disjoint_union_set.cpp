#include<iostream>
#include<list>
using namespace std;

class Graph {
	int V;
	list<pair<int, int>> l; // edge list

public:
	Graph(int V) {
		this->V = V;
	}

	int addEdge(int u, int v) {
		l.push_back(make_pair(u, v));
	}

	//find
	int findSet(int i, int parent[]) {
		if (parent[i] == -1)	return i;

		return findSet(parent[i], parent);
	}

	//union
	int union_set(int x, int y, int parent[]) {
		int s1 = findSet(x, parent);
		int s2 = findSet(y, parent);
		if (s1!=s2) {
			parent[s2] = s1;
		} 
	}

	bool contains_cycle() {
		int *parent = new int[V];
		for (int i=0;i<V;i++) {

			parent[i] = -1;
		}
		for (auto edge : l) {
			int i = edge.first;
			int j = edge.second;
			s1 = findSet(i, parent);
			s2 = findSet(j, parent);

			if (s1 != s2) {
				union(s1, s2);
			} else {
				return true;
			}
		}
		delete [] parent;
		return false;
	}

};

int main() {

	Graph g(4);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 1);

	cout << g.contains_cycle() << endl;
	return 0;
}