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
const int MX = 10001;
int n, m, cnt, SN;
int dfsn[MX << 1], sn[MX << 1];
bool finished[MX << 1];
string board[MX];
vector<int> adj[MX << 1];
stack<int> s;

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
      sn[v] = SN;
      finished[v] = 1;
      if (cur == v) break;
    }
    SN++;
  }

  return res;
}
int main() {
  fastio;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> board[i];
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == '*') {
        int r = 5000 + 2 * (i + 1), c = 2 * (j + 1);
        adj[r].pb(oppo(c));
        adj[c].pb(oppo(r));
        adj[oppo(r)].pb(c);
        adj[oppo(c)].pb(r);
      }

      if (board[i][j] == '#') {
        int r = 5000 + 2 * (i + 1), c = 2 * (j + 1);
        adj[r].pb(c);
        adj[oppo(c)].pb(oppo(r));
        adj[c].pb(r);
        adj[oppo(r)].pb(oppo(c));
      }
    }
  }

  for (int i = 5001; i <= 5000 + 2 * n; ++i) {
    if (dfsn[i] == 0) dfs(i);
  }
  for (int i = 1; i <= 2 * m; ++i) {
    if (dfsn[i] == 0) dfs(i);
  }

  bool ans = 1;
  for (int i = 1; i <= m; ++i) {
    if (sn[2 * i] == sn[2 * i - 1]) {
      ans = 0;
      break;
    }
  }

  if (ans) {
    for (int i = 1; i <= n; ++i) {
      if (sn[2 * i + 5000] == sn[2 * i + 4999]) {
        ans = 0;
        break;
      }
    }
  }

  cout << ans << "\n";
}