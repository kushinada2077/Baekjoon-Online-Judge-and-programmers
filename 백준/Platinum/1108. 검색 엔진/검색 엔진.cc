#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
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

const int MX = 24 * 51 + 1;
int n, x, hash_cnt, cnt, SN;
int dfsn[MX], scc_size[MX], scc[MX], indg[MX];
ll dp[MX];
bool finished[MX], chk[MX][MX];
string su, sv;
stack<int> s;
unordered_map<string, int> s_hash;
vector<int> adj[MX], scc_adj[MX], scc_elem[MX];
vector<pair<int, int>> edge;
int dfs(int cur) {
  dfsn[cur] = ++cnt;
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
      scc_size[SN]++;
      scc_elem[SN].pb(curr);
      if (cur == curr) break;
    }
    SN++;
  }

  return res;
}
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> sv >> x;
    int v;
    if (s_hash[sv] == 0) {
      s_hash[sv] = ++hash_cnt;
      v = hash_cnt;
    } else v = s_hash[sv];
    for (int j = 0; j < x; ++j) {
      cin >> su;
      int u;
      if (s_hash[su] == 0) {
        s_hash[su] = ++hash_cnt;
        u = hash_cnt;
      } else u = s_hash[su];
      adj[u].pb(v);
      edge.pb({u, v});
    }
  }
  cin >> su;

  for (int i = 1; i <= hash_cnt; ++i) {
    if (dfsn[i] == 0) dfs(i);
  }

  int dest = s_hash[su];

  for (auto& [u, v] : edge) {
    if (scc[u] != scc[v]) {
      if (chk[scc[u]][scc[v]] == 0) {
        indg[scc[v]]++;
        scc_adj[scc[u]].pb(scc[v]);
        chk[scc[u]][scc[v]] = 1;
      }
    }
  }

  queue<int> q;
  for (int i = 0; i < SN; ++i) {
    if (indg[i] == 0) {
      q.push(i);
    }
  }

  fill(dp, dp + MX, 1);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    auto& cur_elem_list = scc_elem[cur];
    for (auto& cur_elem : cur_elem_list) {
      for (auto& nxt_elem : adj[cur_elem]) {
        if (scc[cur_elem] == scc[nxt_elem]) continue;
        dp[nxt_elem] += dp[cur_elem];
      }
    }
    for (auto& nxt : scc_adj[cur]) {
      if (--indg[nxt] == 0) q.push(nxt);
    }
  }

  cout << dp[dest] << "\n";
}