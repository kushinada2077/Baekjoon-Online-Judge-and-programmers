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

int V, E, u, v, dfsn[10001], cnt = 1;
vector<int> adj[10001];
vector<vector<int>> scc;
bool finished[10001];
stack<int> s;
int dfs(int cur) {
  dfsn[cur] = cnt++;
  int ret = dfsn[cur];
  s.push(cur);
  for (auto& nxt : adj[cur]) {
    if (dfsn[nxt] == 0) ret = min(ret, dfs(nxt));
    else if (!finished[nxt]) ret = min(ret, dfsn[nxt]);
  }

  if (ret == dfsn[cur]) {
    vector<int> tmp;
    while (1) {
      int curr = s.top();
      s.pop();
      tmp.pb(curr);
      finished[curr] = 1;
      if (curr == cur) break;
    }
    sort(all(tmp));
    scc.pb(tmp);
  }
  return ret;
}
int main() {
  fastio;
  cin >> V >> E;
  for (int i = 0; i < E; ++i) {
    cin >> u >> v;
    adj[u].pb(v);
  }

  for (int i = 1; i <= V; ++i) {
    if (dfsn[i]) continue;
    dfs(i);
  }

  sort(all(scc));
  cout << si(scc) << "\n";
  for (auto& sc : scc) {
    for (auto& i : sc) cout << i << " ";
    cout << "-1\n";
  }
}