#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

int v, e, st, a, b, c;
vector<vector<pair<int, int>>> adj(20005);
vector<int> djikstra(int st) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> dist(v + 5, -1);
  pq.push({0, st});
  dist[st] = 0;

  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();
    if (dist[cur] != d) continue;
    for (auto [c, nxt] : adj[cur]) {
      if (dist[nxt] != -1 && dist[nxt] <= d + c) continue;
      pq.push({c + d, nxt});
      dist[nxt] = c + d;
    }
  }
  return dist;
}
int main() {
  fastio;
  cin >> v >> e >> st;
  for (int i = 0; i < e; ++i) {
    cin >> a >> b >> c;
    adj[a].pb({c, b});
  }
  vector<int> ans = djikstra(st);
  for (int i = 1; i <= v; ++i) {
    if (ans[i] == -1) cout << "INF\n";
    else cout << ans[i] << "\n";
  }
}