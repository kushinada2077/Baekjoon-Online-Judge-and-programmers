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

const int MX = 100001;
int t, n, m, u, v, cnt = 1, SN, dfsn[MX], indg[MX], scc[MX];
bool finished[MX];
vector<int> adj[MX], scc_node[MX];
vector<pair<int, int>> edge;
stack<int> s;

void init() {
  cnt = 1;
  SN = 0;
  edge.clear();
  for (int i = 0; i < n; ++i) {
    finished[i] = dfsn[i] = indg[i] = scc[i] = 0;
    adj[i].clear();
    scc_node[i].clear();
  }
}
int dfs(int cur) {
  dfsn[cur] = cnt++;
  s.push(cur);
  int res = dfsn[cur];

  for (auto& nxt : adj[cur]) {
    if (dfsn[nxt] == 0) res = min(res, dfs(nxt));
    else if (finished[nxt] == 0) res = min(res, dfsn[nxt]);
  }

  if (dfsn[cur] == res) {
    while (1) {
      int curr = s.top();
      s.pop();
      finished[curr] = 1;
      scc[curr] = SN;
      scc_node[SN].pb(curr);
      if (cur == curr) break;
    }
    SN++;
  }
  return res;
}
int main() {
  fastio;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
      cin >> u >> v;
      adj[u].pb(v);
      edge.pb({u, v});
    }
    for (int i = 0; i < n; ++i) {
      if (dfsn[i] == 0) dfs(i);
    }

    for (auto& [u, v] : edge) {
      if (scc[u] != scc[v]) indg[scc[v]]++;
    }

    int node = -1;
    bool f = 1;
    for (int i = 0; i < n; ++i) {
      if (node == -1 && indg[scc[i]] == 0) node = scc[i];
      else if (indg[scc[i]] == 0 && scc[i] != node) {
        f = 0;
        cout << "Confused\n";
        break;
      }
    }

    if (f) {
      sort(all(scc_node[node]));
      for (auto& i : scc_node[node]) cout << i << "\n";
    }
    cout << "\n";
  }
}