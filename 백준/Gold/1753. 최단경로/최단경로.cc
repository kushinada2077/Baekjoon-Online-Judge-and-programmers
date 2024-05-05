#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
vector<pair<int, int>> adj[20001];
const int INF = 0x3f3f3f3f;
int V, E, u, v, w, K;
int d[20001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> V >> E >> K;
  fill(d + 1, d + V + 1, INF);

  while (E--) {
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }

  pq.push({0, K});
  d[K] = 0;

  while (!pq.empty()) {
    auto [cost, cur] = pq.top();
    pq.pop();
    if (cost != d[cur]) continue;

    for (auto [dis, nxt] : adj[cur]) {
      if (d[nxt] <= cost + dis) continue;
      d[nxt] = cost + dis;
      pq.push({d[nxt], nxt});
    }
  }

  for (int i = 1; i <= V; i++) {
    if (d[i] == INF)
      cout << "INF";
    else
      cout << d[i];
    cout << "\n";
  }
}