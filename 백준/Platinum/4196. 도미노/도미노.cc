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

int t, n, m, u, v, dfsn[100001], SN, indg[100001], scc[100001], cnt = 1;
bool finished[100001];
vector<int> adj[100001];
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
      if (curr == cur) break;
    }
    SN++;
  }

  return res;
}
void init() {
  cin >> n >> m;
  for (int i = 0; i < n + 1; ++i) {
    adj[i].clear();
    dfsn[i] = indg[i] = scc[i] = finished[i] = 0;
  }
  cnt = 1;
  SN = 0;
  edge.clear();
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    edge.pb({u, v});
    adj[u].pb(v);
  }
}
int main() {
  fastio;
  cin >> t;
  while (t--) {
    init();

    for (int i = 1; i <= n; ++i) {
      if (dfsn[i] == 0) dfs(i);
    }

    for (auto& [u, v] : edge) {
      indg[scc[v]] += scc[u] != scc[v];
    }

    int ans = 0;
    for (int i = 0; i < SN; ++i) {
      if (indg[i] == 0) ans++;
    }

    cout << ans << "\n";
  }
}