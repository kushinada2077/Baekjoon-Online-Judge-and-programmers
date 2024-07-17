#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

int n, k;
vector<int> bfs(int st, vector<vector<int>>& adj) {
  queue<int> q;
  vector<int> dist(n + 1, -1), ret;
  q.push(st);
  dist[st] = 0;

  while (!q.empty()) {
    auto cur = q.front();
    if (dist[cur] == k) ret.pb(cur);
    q.pop();
    for (auto nxt : adj[cur]) {
      if (dist[nxt] != -1) continue;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
    }
  }
  sort(all(ret));
  return ret;
}

int main() {
  fastio;
  int m, x, v, u;
  cin >> n >> m >> k >> x;
  vector<vector<int>> adj(n + 1);
  for_in(m) {
    cin >> v >> u;
    adj[v].pb(u);
  }
  vector<int> ans = bfs(x, adj);
  if (si(ans) == 0) cout << "-1\n";
  else
    for (auto& i : ans) cout << i << "\n";
}