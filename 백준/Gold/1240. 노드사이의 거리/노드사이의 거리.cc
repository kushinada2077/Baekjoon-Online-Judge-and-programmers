#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, u, v, d, tot;
vector<pair<int, int>> adj[1001];
int vis[1001];
int dfs(int cur, int dis) {
  vis[cur] = 1;
  for (auto nxt_set : adj[cur]) {
    auto nxt = nxt_set.first;
    auto del = nxt_set.second;
    if (v == nxt) {
      tot = dis + del;
      return tot;
    }
    if (vis[nxt]) continue;
    dfs(nxt, dis + del);
  }

  return tot;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N - 1; i++) {
    cin >> u >> v >> d;
    adj[u].push_back({v, d});
    adj[v].push_back({u, d});
  }

  while (M--) {
    cin >> u >> v;
    fill(vis, vis + N + 1, 0);
    cout << dfs(u, 0) << "\n";
  }
}