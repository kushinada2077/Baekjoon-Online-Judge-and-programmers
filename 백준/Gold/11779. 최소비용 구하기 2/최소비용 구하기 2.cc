#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
vector<pair<int, int>> adj[20001];
vector<int> path;
const int INF = 0x3f3f3f3f;
int n, m, u, v, w, s, t;
int d[20001];
int pre[20001];

void djikstra(int st) {
  d[st] = 0;
  pq.push({0, st});

  while (!pq.empty()) {
    auto [cost, cur] = pq.top();
    pq.pop();
    if (d[cur] != cost) continue;

    for (auto [dis, nxt] : adj[cur]) {
      if (d[nxt] <= dis + cost) continue;
      d[nxt] = dis + cost;
      pre[nxt] = cur;
      pq.push({d[nxt], nxt});
    }
  }

  int cur = t;

  while (cur) {
    path.push_back(cur);
    cur = pre[cur];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  fill(d, d + n + 1, INF);

  while (m--) {
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }

  cin >> s >> t;
  djikstra(s);
  cout << d[t] << "\n" << path.size() << "\n";
  for (auto i = path.rbegin(); i < path.rend(); i++) cout << *i << " ";
}