#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

const int MX = 10001;
int n, m, st, en, u, v, SN, cnt = 1;
int dfsn[MX], scc[MX], scc_city_num[MX], indg[MX], dp[MX];
bool finished[MX], poss[MX];
vector<int> adj[MX], scc_adj[MX];
vector<pair<int, int>> edge;
stack<int> s;
int dfs(int cur) {
  dfsn[cur] = cnt++;
  s.push(cur);
  int res = dfsn[cur];

  for (auto& nxt : adj[cur]) {
    if (dfsn[nxt] == 0) res = min(res, dfs(nxt));
    else if (finished[nxt] == 0) res = min(res, dfsn[nxt]);
  }

  if (dfsn[cur] == res) {
    while (1) {
      int curr = s.top();
      s.pop();
      finished[curr] = 1;
      scc[curr] = SN;
      scc_city_num[SN]++;
      if (curr == cur) break;
    }
    SN++;
  }
  return res;
}
int main() {
  fastio;
  cin >> n >> m >> st >> en;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    adj[u].pb(v);
    edge.pb({u, v});
  }
  for (int i = 1; i <= n; ++i) {
    if (dfsn[i] == 0) dfs(i);
  }

  for (auto& [u, v] : edge) {
    if (scc[u] != scc[v]) {
      indg[scc[v]]++;
      scc_adj[scc[u]].pb(scc[v]);
    }
  }

  queue<int> q;

  for (int i = 0; i < SN; ++i) {
    if (indg[i] == 0) {
      q.push(i);
      dp[i] = scc_city_num[i];
    }
  }

  poss[scc[st]] = 1;
  dp[scc[st]] = scc_city_num[scc[st]];
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (auto& nxt : scc_adj[cur]) {
      if (poss[cur]) {
        poss[nxt] = poss[cur];
        dp[nxt] = max(dp[nxt], dp[cur] + scc_city_num[nxt]);
      }
      if (--indg[nxt] == 0) q.push(nxt);
    }
  }

  if (poss[scc[en]]) cout << dp[scc[en]] << "\n";
  else cout << "0\n";
}