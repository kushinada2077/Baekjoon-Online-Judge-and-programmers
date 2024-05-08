#define PAIR pair<long long, int>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const long long INF = 0x7f7f7f7f7f7f;
int N, M, K, u, v, w, ans;
long long d[100001];
vector<int> interview;
vector<PAIR> adj[100001];
priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;

void djikstra() {
  fill(d, d + 1 + N, INF);
  for (auto n : interview) {
    pq.push({0, n});
    d[n] = 0;
  }

  while (!pq.empty()) {
    auto [dis, cur] = pq.top();
    pq.pop();
    if (dis != d[cur]) continue;
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

  cin >> N >> M >> K;
  while (M--) {
    cin >> u >> v >> w;
    adj[v].push_back({w, u});
  }

  while (K--) {
    cin >> u;
    interview.push_back(u);
  }

  djikstra();

  d[0] = -1;
  for (int i = N; i >= 1; i--) {
    if (d[ans] <= d[i]) ans = i;
  }

  cout << ans << "\n" << d[ans];
}