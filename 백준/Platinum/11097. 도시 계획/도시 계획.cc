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

const int MX = 301;
int t, n, SN, cnt = 1;
int dfsn[MX], scc[MX], indg[MX];
bool finished[MX], chk[MX][MX], dp[MX][MX];
string str;
vector<int> scc_elem[MX], adj[MX], scc_adj[MX];
stack<int> s;
void init() {
  cin >> n;
  SN = 0;
  cnt = 1;
  for (int i = 0; i < n + 1; ++i) {
    scc[i] = dfsn[i] = indg[i] = finished[i] = 0;
    scc_elem[i].clear();
    scc_adj[i].clear();
    adj[i].clear();
    for (int j = 0; j < n + 1; ++j) {
      chk[i][j] = dp[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    cin >> str;
    for (int j = 0; j < n; ++j) {
      if (i != j && str[j] == '1') {
        chk[i + 1][j + 1] = 1;
        adj[i + 1].pb(j + 1);
      }
    }
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
      scc_elem[SN].pb(curr);
      if (curr == cur) break;
    }
    SN++;
  }
  return res;
}
int main() {
  fastio;
  cin >> t;
  while (t--) {
    init();
    for (int i = 1; i <= n; ++i) {
      if (dfsn[i] == 0) dfs(i);
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < SN; ++i) {
      auto& ver = scc_elem[i];
      for (int j = 0; j < si(ver) - 1; ++j) ans.pb({ver[j], ver[j + 1]});
      if (si(ver) > 1) ans.pb({ver.back(), ver.front()});
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (scc[i] == scc[j]) continue;
        if (chk[i][j]) dp[scc[i]][scc[j]] = 1;
      }
    }

    for (int i = 0; i < SN; ++i) {
      for (int j = 0; j < SN; ++j) {
        if (dp[i][j] == 0) continue;
        bool is_unit = true;
        for (int k = 0; k < SN; ++k) {
          if (i == k || j == k) continue;
          if (dp[i][k] && dp[k][j]) {
            is_unit = false;
            break;
          }
        }
        if (is_unit) ans.pb({scc_elem[i].front(), scc_elem[j].front()});
      }
    }

    cout << si(ans) << "\n";
    for (auto& [u, v] : ans) cout << u << " " << v << "\n";
    cout << "\n";
  }
}