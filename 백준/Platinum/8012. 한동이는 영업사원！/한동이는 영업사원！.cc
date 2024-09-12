#include <algorithm>
#include <climits>
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

const int MX = 16;
vector<int> adj[30005], depth(30005, -1);
vector<vector<int>> p(MX, vector<int>(30005, -1));
void dfs(int cur) {
  for (auto nxt : adj[cur]) {
    if (depth[nxt] == -1) {
      depth[nxt] = depth[cur] + 1;
      p[0][nxt] = cur;
      dfs(nxt);
    }
  }
}
int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  int diff = depth[u] - depth[v];
  for (int i = 0; diff; ++i) {
    if (diff % 2) u = p[i][u];
    diff >>= 1;
  }

  if (u != v) {
    for (int i = MX - 1; i >= 0; --i) {
      if (p[i][u] != -1 && p[i][u] != p[i][v]) {
        u = p[i][u];
        v = p[i][v];
      }
    }
    u = p[0][u];
  }
  return u;
}
int main() {
  fastio;
  int n, m, u, v;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  depth[1] = 0;
  dfs(1);
  for (int j = 1; j < MX; ++j) {
    for (int i = 1; i <= n; ++i) {
      if (p[j - 1][i] != -1) p[j][i] = p[j - 1][p[j - 1][i]];
    }
  }
  cin >> m;
  u = 1;
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    cin >> v;
    int an = lca(u, v);
    ans += depth[u] + depth[v] - 2 * depth[an];
    u = v;
  }
  cout << ans << "\n";
}