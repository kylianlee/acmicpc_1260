//
// Created by Kylian Lee on 2021/10/05.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adjacent_matrix;
vector<vector<int>> dfs_graph;
vector<bool> dfs_visited;
vector<bool> bfs_visited;

void dfs(int s);
void bfs(int s);

int main(){
  int n, e, s;
  cin >> n >> e >> s;
  adjacent_matrix.resize(n + 1);
  for (int i = 0; i < n + 1; ++i) {
    adjacent_matrix[i].resize(n + 1);
  }
  dfs_visited.resize(n + 1);
  bfs_visited.resize(n + 1);
  int from, to;
  for (int i = 0; i < e; ++i) {
    cin >> from >> to;
    adjacent_matrix[from][to] = 1;
    adjacent_matrix[to][from] = 1;
  }
  dfs_graph = adjacent_matrix;
  dfs(s);
  cout << '\n';
  bfs(s);
  return 0;
}

void dfs(int s){
  dfs_visited[s] = true;
  cout << s << ' ';
  unsigned long len = dfs_graph.size();
  for (int i = 1; i < len; ++i) {
    if(dfs_visited[i] || !dfs_graph[s][i])
      continue;
    dfs(i);
  }
}

void bfs(int s){
  vector<vector<int>> bfs_graph = adjacent_matrix;
  unsigned long len = bfs_graph.size();
  bfs_visited[s] = true;
  queue<int> cache;
  cache.push(s);
  cout << s << ' ';
  while(!cache.empty()){
    s = cache.front();
    for (int i = 1; i < len; ++i) {
      if(!bfs_visited[i] && bfs_graph[s][i]){
        cache.push(i);
        cout << i << ' ';
        bfs_visited[i] = true;
      }
    }
    cache.pop();
  }
}