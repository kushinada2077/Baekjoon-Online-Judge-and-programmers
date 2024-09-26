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

int n, m, u, v, st, p, cnt = 1, SN;
int indg[500001], atm[500001], scc[500001], dfsn[500001], scc_sum[500001], ans[500001];
bool has_r[500001], finished[500001], scc_has_r[500001], scc_poss[500001];
vector<int> adj[500001], scc_adj[500001];
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

  if (res == dfsn[cur]) {
    while (1) {
      int curr = s.top();
      s.pop();
      finished[curr] = 1;
      scc[curr] = SN;
      scc_sum[SN] += atm[curr];
      if (scc_has_r[SN] == 0 && has_r[curr]) scc_has_r[SN] = 1;
      if (curr == cur) break;
    }
    SN++;
  }
  return res;
}

int main() {
  fastio;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    adj[u].pb(v);
    edge.pb({u, v});
  }

  for (int i = 1; i <= n; ++i) cin >> atm[i];
  cin >> st >> p;
  for (int i = 0; i < p; ++i) {
    cin >> u;
    has_r[u] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    if (dfsn[i]) continue;
    dfs(i);
  }

  for (auto& [u, v] : edge) {
    if (scc[u] != scc[v]) {
      scc_adj[scc[u]].pb(scc[v]);
      indg[scc[v]]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < SN; ++i) {
    ans[i] = scc_sum[i];
    if (scc[st] == i) scc_poss[i] = 1;
    if (indg[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (auto& nxt : scc_adj[cur]) {
      if (scc_poss[cur]) {
        scc_poss[nxt] = 1;
        ans[nxt] = max(ans[nxt], ans[cur] + scc_sum[nxt]);
      }
      if (--indg[nxt] == 0) q.push(nxt);
    }
  }

  int anss = -1;
  for (int i = 0; i < SN; ++i) {
    if (scc_poss[i] && scc_has_r[i]) anss = max(anss, ans[i]);
  }
  cout << anss << "\n";
}