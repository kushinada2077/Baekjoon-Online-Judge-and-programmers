#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const ll INF = 0x7f7f7f7f7f7f;
int N, M, A, B, u, v;
ll C, w, d[100001];
vector<PAIR> adj[100001];
priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;

bool djikstra(int limit) {
  fill(d, d + 1 + N, INF);
  pq.push({0, A});
  d[A] = 0;

  while (!pq.empty()) {
    auto [dis, cur] = pq.top();
    pq.pop();
    if (dis > C) continue;
    if (d[cur] != dis) continue;
    for (auto [cost, nxt] : adj[cur]) {
      if (cost > limit) continue;
      if (dis + cost >= d[nxt]) continue;
      d[nxt] = dis + cost;
      pq.push({d[nxt], nxt});
    }
  }

  if (d[B] > C) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> A >> B >> C;
  while (M--) {
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }

  ll st = 1, en = 1000000000;
  while (st < en) {
    int mid = (st + en) / 2;
    if (djikstra(mid))
      en = mid;
    else
      st = mid + 1;
  }

  if (djikstra(st))
    cout << st;
  else
    cout << "-1";
}