#include<iostream>
#include<algorithm>
#include<vector>

void dfs(int start, vector < int > adj[], vector < bool > & visited) {
   visited[start] = true;
   for (auto it: adj[start]) {
     if (visited[it] == false)
       dfs(it, adj, visited);
   }
 }
 bool IsConnected(int s, int V, vector < int > adj[], vector < bool > & mark) {
   vector < bool > visited(26, false);
   dfs(s, adj, visited);

   for (int i = 0; i < 26; i++)
     if (visited[i] == false && mark[i] == true)
       return false;

   return true;
 }
 int isCircle(int V, vector < string > A) {
   vector < bool > mark(26, false);
   vector < int > adj[26];
   vector < int > indegree(26, 0), outdegree(26, 0);
   for (int i = 0; i < V; i++) {
     string s = A[i];
     int u = s[0] - 'a';
     int v = s[s.size() - 1] - 'a';
     mark[u] =  mark[v] = true;
     indegree[v]++, outdegree[u]++;
     adj[u].push_back(v);
   }
   for (int i = 0; i < 26; i++) {
     if (indegree[i] != outdegree[i]) return false;
   }
   return IsConnected(A[0].front() - 'a', 26, adj, mark);
 }