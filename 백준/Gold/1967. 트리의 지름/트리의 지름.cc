#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR_IN_1(n) for (int i = 0; i < n; ++i)
#define FOR_IN_2(i, n) for (int i = 0; i < n; ++i)
#define FOR_IN_3(i, m, n) for (int i = m; i < n; ++i)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define for_in(...) GET_MACRO(__VA_ARGS__, FOR_IN_3, FOR_IN_2, FOR_IN_1)(__VA_ARGS__)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

int n;
int dis[10005];
vector<vector<pair<int, int>>> adj(10005);
pair<int, int> max_distance(int v) {
  int ret = v;
  queue<int> q;
  fill(dis, dis + n + 1, -1);
  q.push(v);
  dis[v] = 0;
  while (!q.empty()) {
    auto cur = q.front();
    if (dis[cur] > dis[ret]) ret = cur;
    q.pop();
    for (auto [nxt, c] : adj[cur]) {
      if (dis[nxt] != -1) continue;
      q.push(nxt);
      dis[nxt] = dis[cur] + c;
    }
  }
  return {ret, dis[ret]};
}
int main() {
  fastio;
  int v, u, c;
  cin >> n;
  for_in(n - 1) {
    cin >> v >> u >> c;
    adj[v].pb({u, c});
    adj[u].pb({v, c});
  }
  auto [a, c1] = max_distance(1);
  auto [b, c2] = max_distance(a);
  cout << c2;
}