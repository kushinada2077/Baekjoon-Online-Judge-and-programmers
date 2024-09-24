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

vector<pair<int, int>> adj[10001], adj_r[10001];
int indg[10001], est[10001];
int main() {
  fastio;
  int n, m, u, v, c, st, en;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> c;
    adj[u].pb({c, v});
    adj_r[v].pb({c, u});
    indg[v]++;
  }
  cin >> st >> en;

  queue<int> q;
  q.push(st);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto& [c, nxt] : adj[cur]) {
      est[nxt] = max(est[nxt], est[cur] + c);
      if (--indg[nxt] == 0) {
        q.push(nxt);
      }
    }
  }

  stack<int> s;
  s.push(en);
  vector<bool> vis(n + 1);
  int ans = 0;
  while (!s.empty()) {
    int cur = s.top();
    s.pop();
    if (vis[cur]) continue;
    vis[cur] = 1;
    for (auto& [c, nxt] : adj_r[cur]) {
      if (est[nxt] + c == est[cur]) {
        ans++;
        s.push(nxt);
      }
    }
  }

  cout << est[en] << "\n" << ans << "\n";
}