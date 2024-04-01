#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int adj[101][101];
int N, x;

bool bfs(int v, int dest) {
  queue<int> q;
  bool vis[101];
  fill(vis + 1, vis + 1 + N, false);
  q.push(v);

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int i = 1; i < N + 1; i++) {
      if (adj[cur][i] == 0) continue;
      if (vis[i]) continue;
      if (i == dest) return true;
      q.push(i);
      vis[i] = true;
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      cin >> x;
      adj[i][j] = x;
    }
  }

  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      cout << bfs(i, j) << " ";
    }
    cout << "\n";
  }
}