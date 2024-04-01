#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[1001];
queue<int> q;
bool vis[1001];

void dfs(int V) {
  vis[V] = true;
  cout << V << " ";
  for (auto nxt : adj[V]) {
    if (vis[nxt]) continue;
    dfs(nxt);
  }
}

void bfs(int V) {
  q.push(V);
  vis[V] = true;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    cout << cur << " ";
    for (auto nxt : adj[cur]) {
      if (vis[nxt]) continue;
      q.push(nxt);
      vis[nxt] = true;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M, V, v1, v2;
  cin >> N >> M >> V;
  while (M--) {
    cin >> v1 >> v2;
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }

  for (int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());
  dfs(V);
  fill(vis + 1, vis + 1 + N, false);
  cout << "\n";
  bfs(V);
}