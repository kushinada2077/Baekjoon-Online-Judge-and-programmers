#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

const int MX = 100001;
int n, m, u, v, cnt, dup;
int dfsn[MX], chk[MX];
vector<int> adj[MX];
vector<vector<pair<int, int>>> bcc;
stack<pair<int, int>> s;

int dfs(int cur, int prev = -1) {
  int res = dfsn[cur] = ++cnt;

  for (auto& nxt : adj[cur]) {
    if (nxt == prev) continue;
    if (dfsn[cur] > dfsn[nxt]) s.push({cur, nxt});
    if (dfsn[nxt] > 0) res = min(res, dfsn[nxt]);
    else {
      int tmp = dfs(nxt, cur);
      res = min(res, tmp);
      if (tmp >= dfsn[cur]) {
        vector<pair<int, int>> edge;
        while (1) {
          auto [u, v] = s.top();
          s.pop();
          edge.pb({u, v});
          if (u == cur && v == nxt) break;
        }
        bcc.pb(edge);
      }
    }
  }
  return res;
}

int main() {
  fastio;
  cin >> n >> m;
  rep(m) {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  for (int i = 1; i <= n; ++i) {
    if (dfsn[i] == 0) dfs(i);
  }

  int cntt = 0;
  for (int i = 0; i < si(bcc); ++i) {
    auto& edge_list = bcc[i];
    if (si(edge_list) > 2) {
      set<int> v_list;
      for (auto& [u, v] : edge_list) {
        if ((chk[u] && chk[u] != i + 1) || chk[v] && chk[v] != i + 1) {
          cout << "Not cactus\n";
          return 0;
        }
        v_list.insert(u);
        v_list.insert(v);
        chk[u] = chk[v] = i + 1;
      }
      if (si(edge_list) != si(v_list)) {
        cout << "Not cactus\n";
        return 0;
      }
    }
  }

  cout << "Cactus\n";
}