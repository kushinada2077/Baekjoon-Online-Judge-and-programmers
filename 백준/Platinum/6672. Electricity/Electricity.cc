#include <algorithm>
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

const int MX = 10001;
int n, m, u, v, ans, cnt, root, mx;
int dfsn[MX], bccCnt[MX];
vector<int> adj[MX];
void init() {
  cin >> n >> m;
  ans = cnt = 0;
  mx = 1;
  rep(n + 1) {
    adj[i].clear();
    dfsn[i] = bccCnt[i] = 0;
  }
}
int dfs(int cur, int prev = -1) {
  int res = dfsn[cur] = ++cnt;
  for (auto& nxt : adj[cur]) {
    if (nxt == prev) continue;
    if (dfsn[nxt] > 0) res = min(res, dfsn[nxt]);
    else {
      int tmp = dfs(nxt, cur);
      res = min(res, tmp);
      if (tmp >= dfsn[cur]) mx = max(mx, ++bccCnt[cur]);
    }
  }
  if (cur != root) mx = max(mx, ++bccCnt[cur]);
  return res;
}
int main() {
  fastio;
  while (1) {
    init();
    if (n == 0 && m == 0) break;
    if (m == 0) {
      cout << n - 1 << "\n";
      continue;
    }
    rep(m) {
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    rep(n) {
      if (dfsn[i] == 0) {
        ans++;
        root = i;
        dfs(i);
      }
    }
    cout << ans + mx - 1 << "\n";
  }
}