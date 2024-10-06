#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
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

const int MX = 100001;
int n, m, u, v, cnt = 1;
int dfsn[MX];
vector<int> adj[MX];
set<pair<int, int>> ans;

int DFS(int cur, int prev = -1) {
  int res = dfsn[cur] = cnt++;
  for (auto& nxt : adj[cur]) {
    if (nxt == prev) continue;
    if (dfsn[nxt] > 0) res = min(res, dfsn[nxt]);
    else {
      int tmp = DFS(nxt, cur);
      res = min(res, tmp);
      if (tmp > dfsn[cur]) ans.insert({min(cur, nxt), max(cur, nxt)});
    }
  }
  return res;
}
int main() {
  fastio;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  for (int i = 1; i <= n; ++i) {
    if (dfsn[i] == 0) DFS(i);
  }

  cout << si(ans) << "\n";
  for (auto& [u, v] : ans) cout << u << " " << v << "\n";
}