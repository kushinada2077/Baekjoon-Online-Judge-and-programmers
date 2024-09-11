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

int p[100005][18];
vector<int> adj[100005], depth(100005, -1);
void dfs(int cur) {
  for (auto nxt : adj[cur]) {
    if (depth[nxt] == -1) {
      depth[nxt] = depth[cur] + 1;
      p[nxt][0] = cur;
      dfs(nxt);
    }
  }
}
int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  int diff = depth[u] - depth[v];
  for (int i = 0; (1 << i) <= diff; ++i) {
    if (diff & (1 << i)) {
      u = p[u][i];
    }
  }

  if (v != u) {
    for (int j = 17; j >= 0; --j) {
      if (p[u][j] != -1 && p[v][j] != p[u][j]) {
        v = p[v][j];
        u = p[u][j];
      }
    }
    u = p[u][0];
  }
  return u;
}
int main() {
  fastio;
  int n, m, v, u;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> v >> u;
    adj[v].pb(u);
    adj[u].pb(v);
  }
  depth[1] = 0;
  dfs(1);
  for (int k = 1; k < 18; ++k) {
    for (int i = 1; i <= n; ++i) {
      if (p[i][k - 1] != -1) p[i][k] = p[p[i][k - 1]][k - 1];
    }
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    cout << lca(u, v) << "\n";
  }
}