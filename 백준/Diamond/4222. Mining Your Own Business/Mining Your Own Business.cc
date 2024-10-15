#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define L_PATH "input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;

const int MX = 100001;
int n, m, cnt, BN, root, t = 1;
int dfsn[MX];
map<int, vector<int>> adj;
set<int> cut, bcc[MX << 1];
stack<pair<int, int>> s;
void init() {
  n = cnt = BN = 0;
  adj.clear();
  cut.clear();
  for (int i = 0; i < MX; ++i) {
    if (i < MX) dfsn[i] = 0;
    bcc[i].clear();
  }
}
int dfs(int cur, int prev = -1) {
  int res = dfsn[cur] = ++cnt, child{};

  for (auto& nxt : adj[cur]) {
    if (nxt == prev) continue;
    if (dfsn[cur] > dfsn[nxt]) s.push({cur, nxt});
    if (dfsn[nxt] > 0) res = min(res, dfsn[nxt]);
    else {
      child++;
      int tmp = dfs(nxt, cur);
      res = min(res, tmp);
      if (tmp >= dfsn[cur]) {
        if (cur != root && child) cut.insert(cur);
        while (1) {
          auto [u, v](s.top());
          s.pop();
          bcc[BN].insert(u);
          bcc[BN].insert(v);
          if (u == cur && v == nxt) break;
        }
        BN++;
      }
    }
  }
  if (cur == root && child > 1) cut.insert(cur);
  return res;
}
int main() {
  fastio;
  while (t++) {
    init();
    cin >> m;
    if (m == 0) break;
    for (int u, v; m--;) {
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
      n = max({n, u, v});
    }

    for (int i = 1; i <= n; ++i) {
      if (dfsn[i] == 0) {
        root = i;
        dfs(i);
      }
    }

    ll ans1{}, ans2 = 1;

    if (BN == 1) {
      ans2 = 1ll * n * (n - 1) / 2;
      cout << "Case " << t - 1 << ": " << 2 << " " << ans2 << "\n";
      continue;
    }
    for (int i = 0; i < BN; ++i) {
      auto& _bcc = bcc[i];
      int cnt{};
      for (auto& v : _bcc) {
        if (cut.contains(v)) cnt++;
      }
      if (cnt == 1) {
        ans1++;
        ans2 = ans2 * (si(_bcc) - 1);
      }
    }
    cout << "Case " << t - 1 << ": " << ans1 << " " << ans2 << "\n";
  }
}