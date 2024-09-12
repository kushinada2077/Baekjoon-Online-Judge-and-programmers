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

vector<vector<int>> p, children;
vector<int> depth;
void dfs(int cur) {
  for (auto nxt : children[cur]) {
    depth[nxt] = depth[cur] + 1;
    dfs(nxt);
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
    for (int i = 14; i >= 0; --i) {
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
  int t, n, a, b;
  cin >> t;
  while (t--) {
    cin >> n;
    p = vector<vector<int>>(15, vector<int>(n + 5, -1));
    depth = vector<int>(n + 5, -1);
    children = vector<vector<int>>(n + 5);
    for (int i = 0; i < n - 1; ++i) {
      cin >> a >> b;
      children[a].pb(b);
      p[0][b] = a;
    }
    int r;
    for (int i = 1; i <= n; ++i) {
      if (p[0][i] == -1) {
        r = i;
        break;
      }
    }

    depth[r] = 0;
    dfs(r);

    for (int j = 1; j < 15; ++j) {
      for (int i = 1; i <= n; ++i) {
        if (p[j - 1][i] != -1) p[j][i] = p[j - 1][p[j - 1][i]];
      }
    }

    cin >> a >> b;
    cout << lca(a, b) << "\n";
  }
}