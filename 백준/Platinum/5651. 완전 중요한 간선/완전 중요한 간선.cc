#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
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
using T = tuple<int, int, int>;
using P = pair<int, int>;

const int MX = 301;
int t, n, m, c[MX][MX], f[MX][MX];
vector<int> adj[MX];
vector<P> path;
void init() {
  path.clear();
  for (int i = 0; i < MX; ++i) {
    adj[i].clear();
    for (int j = 0; j < MX; ++j) c[i][j] = c[j][i] = f[i][j] = f[j][i] = 0;
  }
}
int main() {
  fastio;
  cin >> t;
  while (t--) {
    init();
    cin >> n >> m;
    int ans = 0;
    for (int u, v, w, i{}; i < m; ++i) {
      cin >> u >> v >> w;
      adj[u].pb(v);
      adj[v].pb(u);
      c[u][v] += w;
      path.pb(P(u, v));
    }

    while (1) {
      queue<int> q;
      vector<int> prev(MX, -1);
      q.push(1);
      prev[1] = 0;

      while (!q.empty() && prev[n] == -1) {
        int cur = q.front();
        q.pop();
        for (auto nxt : adj[cur]) {
          if (prev[nxt] == -1 && c[cur][nxt] - f[cur][nxt] > 0) {
            q.push(nxt);
            prev[nxt] = cur;
            if (nxt == n) break;
          }
        }
      }

      if (prev[n] == -1) break;
      int flow = INF;
      for (int i = n; i != 1; i = prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
      for (int i = n; i != 1; i = prev[i]) {
        f[prev[i]][i] += flow;
        f[i][prev[i]] -= flow;
      }
    }

    for (auto [u, v] : path) {
      if (c[u][v] == f[u][v]) {
        queue<int> q;
        q.push(u);
        vector<bool> vis(MX, 0);
        vis[u] = 1;

        while (!q.empty() && vis[v] == 0) {
          int cur = q.front();
          q.pop();
          for (auto nxt : adj[cur]) {
            if (vis[nxt] == 0 && c[cur][nxt] > f[cur][nxt]) {
              q.push(nxt);
              vis[nxt] = 1;
              if (nxt == v) break;
            }
          }
        }

        if (vis[v] == 0) ans++;
      }
    }

    cout << ans << "\n";
  }
}