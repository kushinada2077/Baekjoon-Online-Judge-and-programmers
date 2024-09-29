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

int n, m, u, v, dfsn[5001], SN, oudg[5001], scc[5001], cnt = 1;
bool finished[5001];
vector<int> adj[5001];
vector<pair<int, int>> edge;
stack<int> s;
void init() {
  cnt = 1;
  SN = 0;
  edge.clear();
  for (int i = 0; i < n + 1; ++i) {
    oudg[i] = dfsn[i] = finished[i] = scc[i] = 0;
    adj[i].clear();
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

  if (res == dfsn[cur]) {
    while (1) {
      int curr = s.top();
      s.pop();
      finished[curr] = 1;
      scc[curr] = SN;
      if (cur == curr) break;
    }
    SN++;
  }

  return res;
}
int main() {
  fastio;
  while (1) {
    cin >> n;
    if (n == 0) break;
    cin >> m;
    init();
    for (int i = 0; i < m; ++i) {
      cin >> u >> v;
      adj[u].pb(v);
      edge.pb({u, v});
    }
    for (int i = 1; i <= n; ++i) {
      if (dfsn[i] == 0) dfs(i);
    }

    for (auto& [u, v] : edge) {
      if (scc[u] != scc[v]) oudg[scc[u]]++;
    }
    for (int i = 1; i <= n; ++i) {
      int node = scc[i];
      if (oudg[node] == 0) cout << i << " ";
    }
    cout << "\n";
  }
}