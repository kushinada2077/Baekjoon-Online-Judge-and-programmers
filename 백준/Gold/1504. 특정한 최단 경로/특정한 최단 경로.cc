#define PAIR pair<int, int>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[2][801];
int N, E, u, v, w, v1, v2, d1, d2, d3, mn1, mn2;
vector<PAIR> adj[1001];

void djikstra(int st, int v) {
  priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
  fill(d[v] + 1, d[v] + 1 + N, INF);
  d[v][st] = 0;
  pq.push({0, st});

  while (!pq.empty()) {
    auto [dis, cur] = pq.top();
    pq.pop();
    if (dis != d[v][cur]) continue;
    for (auto [cost, nxt] : adj[cur]) {
      if (cost + dis >= d[v][nxt]) continue;
      d[v][nxt] = cost + dis;
      pq.push({d[v][nxt], nxt});
    }
  }
}

void solve() {
  djikstra(v1, 0);
  djikstra(v2, 1);

  d1 = d[0][1];
  d2 = d[0][v2];
  d3 = d[1][N];

  if (d1 == INF || d2 == INF || d3 == INF)
    mn1 = INF;
  else
    mn1 = d1 + d2 + d3;

  d1 = d[1][1];
  d2 = d[1][v1];
  d3 = d[0][N];

  if (d1 == INF || d2 == INF || d3 == INF)
    mn2 = INF;
  else
    mn2 = d1 + d2 + d3;

  int ans = -1;
  if (mn1 != INF || mn2 != INF) ans = min(mn1, mn2);
  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> E;

  while (E--) {
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }

  cin >> v1 >> v2;

  solve();
}