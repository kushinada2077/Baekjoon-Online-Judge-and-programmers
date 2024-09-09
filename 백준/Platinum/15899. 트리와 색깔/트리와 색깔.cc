#include <algorithm>
#include <iostream>
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

const int MOD = 1e9 + 7, _size = 1 << 18;
vector<int> seg[_size << 1], v2c(200005), adj[200005];
vector<bool> vis(200005);
pair<int, int> section[200005];
int idx = 1;
void dfs(int cur) {
  section[cur].X = idx;
  seg[_size + idx++].pb(v2c[cur]);
  for (auto& nxt : adj[cur]) {
    if (vis[nxt]) continue;
    vis[nxt] = true;
    dfs(nxt);
  }
  section[cur].Y = idx;
}
void construct() {
  for (int i = _size - 1; i != 0; --i) {
    vector<int>&c = seg[i], l = seg[i << 1], r = seg[i << 1 | 1];
    c.resize(si(l) + si(r));
    for (int j = 0, p = 0, q = 0; j < si(l) + si(r); ++j) {
      if (q == si(r) || (p < si(l) && l[p] <= r[q])) c[j] = l[p++];
      else c[j] = r[q++];
    }
  }
}
int find(int node, int st, int en, int l, int r, int k) {
  if (en <= l || r <= st || si(seg[node]) == 0) return 0;
  if (l <= st && en <= r) return upper_bound(all(seg[node]), k) - seg[node].begin();
  int mid = (st + en) / 2;
  return find(node << 1, st, mid, l, r, k) + find(node << 1 | 1, mid, en, l, r, k);
}
int main() {
  fastio;
  int n, m, C, x, u, v, c;
  cin >> n >> m >> C;
  for (int i = 1; i <= n; ++i) cin >> v2c[i];
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  vis[ROOT] = true;
  dfs(ROOT);
  construct();

  ll ans = 0;
  for (int i = 0; i < m; ++i) {
    cin >> v >> c;
    auto [l, r] = section[v];
    ans += find(ROOT, 0, _size, l, r, c);
    ans %= MOD;
  }
  cout << ans << "\n";
}