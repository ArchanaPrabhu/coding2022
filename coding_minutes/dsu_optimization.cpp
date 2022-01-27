

// there are 2 optimization which make the time complexity O(1)

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
	// we do path compression opt
	int findSet(int i, int parent[]) {
		if (parent[i] == -1)	return i;

		return parent[i] = findSet(parent[i], parent); // we make tthe node's super parent as the immediate parent
	}

	//union
	int union_set(int x, int y, int parent[], int rank[]) {
		int s1 = findSet(x, parent);
		int s2 = findSet(y, parent);
		if (s1!=s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];

			}
		} 
	}

	bool contains_cycle() {
		int *parent = new int[V];
		int *rank = new intt[V];
		for (int i=0;i<V;i++) {
			parent[i] = -1;
			rank[i] = 1; // each set contains 1 node initially
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