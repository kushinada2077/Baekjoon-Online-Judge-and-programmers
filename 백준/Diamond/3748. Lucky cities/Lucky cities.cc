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

// bcc별로 홀수 싸이클이 존재하는지 찾아내고 존재하면 해당 BCC의 모든 정점을 정답에 추가
const int MX = 100001;
int t, n, m, u, v, cnt;
int dfsn[MX], depth[MX];
vector<int> adj[MX];
vector<set<int>> bcc;
set<int> ans;
stack<pair<int, int>> s;
void init() {
  cin >> n >> m;
  cnt = 0;
  bcc.clear();
  ans.clear();
  rep(n + 1) {
    adj[i].clear();
    dfsn[i] = 0;
  }
}
void bfs(int start) {
  queue<int> q;
  q.push(start);
  depth[start] = 0;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto& nxt : adj[cur]) {
      if (depth[nxt] != -1) continue;
      q.push(nxt);
      depth[nxt] = depth[cur] + 1;
    }
  }
}
int dfs(int cur, int prev = -1) {
  int res = dfsn[cur] = ++cnt;
  for (auto& nxt : adj[cur]) {
    if (prev == cur) continue;
    if (dfsn[cur] > dfsn[nxt]) s.push({cur, nxt});
    if (dfsn[nxt] > 0) res = min(res, dfsn[nxt]);
    else {
      int tmp = dfs(nxt, cur);
      res = min(res, tmp);
      if (tmp >= dfsn[cur]) {
        set<int> bcc_v;
        while (1) {
          auto [u, v] = s.top();
          s.pop();
          bcc_v.insert(u);
          bcc_v.insert(v);
          if (u == cur && v == nxt) break;
        }
        bcc.pb(bcc_v);
      }
    }
  }
  return res;
}
int main() {
  fastio;
  cin >> t;
  while (t--) {
    init();
    rep(m) {
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }

    for (int i = 1; i <= n; ++i) {
      if (dfsn[i] == 0) dfs(i);
    }

    for (auto& bc : bcc) {
      bool f = 0;
      for (auto& cur : bc) depth[cur] = -1;
      bfs(*bc.begin());
      for (auto& cur : bc) {
        for (auto& nxt : adj[cur]) {
          if (!bc.contains(nxt)) continue;
          if (depth[cur] == depth[nxt]) {
            f = 1;
            break;
          }
        }
        if (f) break;
      }
      if (f) {
        for (auto& cur : bc) ans.insert(cur);
      }
    }

    cout << si(ans) << "\n";
  }
}