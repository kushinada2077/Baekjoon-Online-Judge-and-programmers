#define PAIR pair<int, int>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[1001], N, M, st, en, u, v, w;
vector<PAIR> adj[1001];

void djikstra(int n) {
  priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
  fill(d + 1, d + 1 + N, INF);
  d[n] = 0;
  pq.push({0, n});

  while (!pq.empty()) {
    auto [dis, cur] = pq.top();
    pq.pop();
    if (d[cur] != dis) continue;
    for (auto [cost, nxt] : adj[cur]) {
      if (cost + dis >= d[nxt]) continue;
      d[nxt] = cost + dis;
      pq.push({d[nxt], nxt});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  while (M--) {
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }

  cin >> st >> en;
  djikstra(st);
  cout << d[en];
}