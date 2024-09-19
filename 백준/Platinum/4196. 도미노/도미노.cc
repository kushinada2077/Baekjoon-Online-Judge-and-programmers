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

int t, n, m, a, b, cnt;
vector<vector<int>> scc;
vector<int> adj[100005], dfsn, sn, indg;
vector<pair<int, int>> edge;
vector<bool> finished;
stack<int> s;
void init() {
  cnt = 1;
  for (int i = 0; i < n + 5; ++i) adj[i].clear();
  dfsn = vector<int>(n + 5);
  sn = vector<int>(n + 5);
  indg = vector<int>(n + 5);
  scc.clear();
  s = stack<int>();
  finished = vector<bool>(n + 5);
  edge.clear();
}
int dfs(int cur) {
  dfsn[cur] = cnt++;
  s.push(cur);

  int ret = dfsn[cur];
  for (auto& nxt : adj[cur]) {
    if (!dfsn[nxt]) ret = min(ret, dfs(nxt));
    else if (!finished[nxt]) ret = min(ret, dfsn[nxt]);
  }

  if (ret == dfsn[cur]) {
    vector<int> tmp;
    while (1) {
      int t = s.top();
      s.pop();
      sn[t] = si(scc);
      finished[t] = 1;
      tmp.pb(t);
      if (t == cur) break;
    }
    scc.pb(tmp);
  }
  return ret;
}
int main() {
  fastio;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int ans = 0;
    init();
    for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      adj[a].pb(b);
      edge.pb({a, b});
    }

    for (int i = 1; i <= n; ++i) {
      if (dfsn[i]) continue;
      dfs(i);
    }

    for (auto& [a, b] : edge) {
      if (sn[a] != sn[b]) indg[sn[b]]++;
    }
    for (int i = 0; i < si(scc); ++i) {
      if (!indg[i]) ans++;
    }

    cout << ans << "\n";
  }
}