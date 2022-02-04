#include<iostream>
using namespace std;

bool vis[N];
vector<int> g[N]; // array of vectors
int depth[N], height[N];

void dfs(int vertex, int parent = 0) {
	// take action on vertex before entering the vertex.
	vis[vertex] = true;
	for (int child : g[vertex]) {
		// take action on child before entering the child.
		if (child == parent) continue;

		dept[child] = depth[vertex] + 1;
		dfs(child, vertex);
		// take action on the child after exiting the child.

		height[vertex] = mac[height[vertex], height[child] + 1];
	}
}

int main() {

	for (int i=1;i<=n;i++) {
		cout << depth[i] << " " << height[i];
	}

}