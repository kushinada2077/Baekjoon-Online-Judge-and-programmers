#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int V, E, K, u, v, w, d[20001];
vector<pair<int, int>> adj[20001];

void dijkstra(int st) {
  fill(d, d + 1 + V, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  d[st] = 0;
  pq.push({0, st});

  while (!pq.empty()) {
    auto [dis, cur] = pq.top();
    pq.pop();
    if (d[cur] < dis) continue;

    for (auto [nxt, cost] : adj[cur]) {
      if (d[nxt] <= d[cur] + cost) continue;
      d[nxt] = d[cur] + cost;
      pq.push({d[nxt], nxt});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> V >> E >> K;

  while (E--) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  dijkstra(K);
  for (int i = 1; i <= V; i++) {
    if (d[i] == INF)
      cout << "INF\n";
    else
      cout << d[i] << "\n";
  }
}