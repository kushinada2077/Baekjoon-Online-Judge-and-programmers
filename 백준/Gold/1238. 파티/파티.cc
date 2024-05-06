#define PAIR pair<int, int>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, X, d[1001];
int u, v, w, ans;
vector<PAIR> adj[1001];

int djikstra(int st, int en) {
  priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
  fill(d + 1, d + 1 + N, INF);
  d[st] = 0;
  pq.push({0, st});

  while (!pq.empty()) {
    auto [dis, cur] = pq.top();
    pq.pop();
    if (dis != d[cur]) continue;
    for (auto [cost, nxt] : adj[cur]) {
      if (dis + cost >= d[nxt]) continue;
      d[nxt] = dis + cost;
      pq.push({d[nxt], nxt});
    }
  }

  return d[en];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> X;
  while (M--) {
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }

  for (int i = 1; i <= N; i++) {
    int max_time = djikstra(i, X) + djikstra(X, i);
    if (ans < max_time) ans = max_time;
  }

  cout << ans;
}