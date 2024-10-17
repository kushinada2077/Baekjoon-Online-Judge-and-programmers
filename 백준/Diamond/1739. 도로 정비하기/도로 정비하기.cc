#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define L_PATH "input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using T = tuple<int, int, int>;
using P = pair<int, int>;

inline int oppo(int v) { return v % 2 ? v + 1 : v - 1; }
const int MX = 10001, TR = 3000;
int t, n, m, k, cnt, SN;
int dfsn[MX], sn[MX];
bool finished[MX];
vector<int> adj[MX];
stack<int> s;

void init() {
  cnt = SN = 0;
  for (int i = 0; i < MX; ++i) {
    dfsn[i] = sn[i] = finished[i] = 0;
    adj[i].clear();
  }
}
int dfs(int cur) {
  int res = dfsn[cur] = ++cnt;
  s.push(cur);

  for (auto& nxt : adj[cur]) {
    if (dfsn[nxt] == 0) res = min(res, dfs(nxt));
    else if (finished[nxt] == 0) res = min(res, dfsn[nxt]);
  }

  if (res == dfsn[cur]) {
    while (1) {
      int v = s.top();
      s.pop();
      finished[v] = 1;
      sn[v] = SN;
      if (cur == v) break;
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
    cin >> n >> m >> k;
    for (int r1, r2, c1, c2; k--;) {
      cin >> r1 >> c1 >> r2 >> c2;
      if (r1 == r2 && c1 == c2) continue;
      int a = TR + r1 * 2, c = TR + r2 * 2, b = c1 * 2, d = c2 * 2;
      if (r1 > r2) {
        b = oppo(b);
        d = oppo(d);
      }
      if (c1 > c2) {
        a = oppo(a);
        c = oppo(c);
      }
      if (r1 == r2) adj[oppo(a)].pb(a);
      else if (c1 == c2) adj[oppo(b)].pb(b);
      else {
        adj[oppo(a)].pb(b);
        adj[oppo(b)].pb(a);
        adj[oppo(a)].pb(c);
        adj[oppo(c)].pb(a);
        adj[oppo(b)].pb(d);
        adj[oppo(d)].pb(b);
        adj[oppo(c)].pb(d);
        adj[oppo(d)].pb(c);
      }
    }

    for (int i = TR + 1; i <= TR + 2 * n; ++i) {
      if (dfsn[i] == 0) dfs(i);
    }
    for (int i = 1; i <= 2 * m; ++i) {
      if (dfsn[i] == 0) dfs(i);
    }

    bool ans = 1;
    for (int i = 1; i <= n; ++i) {
      if (sn[TR + 2 * i] == sn[TR + 2 * i - 1]) {
        ans = 0;
        break;
      }
    }

    if (ans) {
      for (int i = 1; i <= m; ++i) {
        if (sn[2 * i] == sn[2 * i - 1]) {
          ans = 0;
          break;
        }
      }
    }

    if (ans) cout << "Yes\n";
    else cout << "No\n";
  }
}