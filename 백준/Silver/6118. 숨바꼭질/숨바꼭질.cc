#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, u, v, mx = -1;
vector<int> adj[20001];
int dis[20001];
int ans[3];
queue<int> q;

void bfs(int v) {
  q.push(v);
  dis[v] = 0;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (auto nxt : adj[cur]) {
      if (dis[nxt] != -1) continue;
      q.push(nxt);
      dis[nxt] = dis[cur] + 1;
      if (dis[nxt] > mx) mx = dis[nxt];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  while (M--) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  fill(dis, dis + N + 1, -1);
  bfs(1);
  ans[1] = mx;
  for (int i = N; i > 0; i--) {
    if (dis[i] == mx) {
      ans[0] = i;
      ans[2]++;
    }
  }

  for (auto n : ans) cout << n << " ";
}