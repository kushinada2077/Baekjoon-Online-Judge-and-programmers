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

int t, n, m, u, v;
int a[501], indg[501], _rank[501];

bool chk[501][501];
vector<int> adj[501];
void init() {
  for (int i = 0; i < n + 1; ++i) {
    _rank[i] = indg[i] = 0;
    adj[i].clear();
    for (int j = 0; j < n + 1; ++j) chk[i][j] = 0;
  }
}
int main() {
  fastio;
  cin >> t;
  while (t--) {
    cin >> n;
    init();
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      _rank[a[i]] = i;
    }
    cin >> m;
    while (m--) {
      cin >> u >> v;
      if (_rank[u] < _rank[v]) swap(u, v);
      adj[u].pb(v);
      indg[v]++;
      chk[v][u] = true;
    }
    for (int i = 0; i < n; ++i) {
      u = a[i];
      for (int j = i + 1; j < n; ++j) {
        v = a[j];
        if (chk[u][v]) continue;
        adj[u].pb(v);
        indg[v]++;
      }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
      if (indg[i] == 0) q.push(i);
    }

    bool f = false;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (si(q) == 0) {
        cout << "IMPOSSIBLE\n";
        f = true;
        break;
      } else if (si(q) > 1) {
        cout << "?\n";
        f = true;
        break;
      }
      int cur = q.front();
      q.pop();
      for (auto& nxt : adj[cur]) {
        if (--indg[nxt] == 0) q.push(nxt);
      }
      ans.pb(cur);
    }

    if (f) continue;

    for (auto& i : ans) cout << i << " ";
    cout << "\n";
  }
}