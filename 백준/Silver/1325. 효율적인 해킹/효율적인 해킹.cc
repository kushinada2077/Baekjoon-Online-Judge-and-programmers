#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, v1, v2;
vector<int> adj[10001];
vector<int> ans{0};

int bfs(int V) {
  queue<int> q;
  int cnt = 0;
  bool vis[N + 1];
  fill(vis + 1, vis + 1 + N, false);
  q.push(V);
  vis[V] = true;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (auto nxt : adj[cur]) {
      if (vis[nxt]) continue;
      q.push(nxt);
      vis[nxt] = true;
      cnt++;
    }
  }

  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  while (M--) {
    cin >> v1 >> v2;
    adj[v2].push_back(v1);
  }

  for (int v = 1; v < N + 1; v++) {
    ans.push_back(bfs(v));
  }

  int mx = *max_element(ans.begin(), ans.end());

  for (int i = 1; i < N + 1; i++) {
    if (mx == ans[i]) cout << i << " ";
  }
}