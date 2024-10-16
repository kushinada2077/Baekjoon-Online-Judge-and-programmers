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
const int MX = 2001;
int t, cnt, SN;
int dfsn[MX << 1], sn[MX << 1];
bool finished[MX << 1];
vector<int> adj[MX << 1];
stack<int> s;

void init() {
  cnt = SN = 0;
  for (int i = 0; i < (MX << 1); ++i) {
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
  for (int n, m, i{}; i < t; ++i) {
    init();
    cin >> n >> m;
    for (int a, b; m--;) {
      cin >> a >> b;
      a = a > 0 ? 2 * a : 2 * -a - 1;
      b = b > 0 ? 2 * b : 2 * -b - 1;
      adj[oppo(a)].pb(b);
      adj[a].pb(oppo(b));
      adj[oppo(b)].pb(a);
      adj[b].pb(oppo(a));
    }

    for (int i = 1; i <= 2 * n; ++i) {
      if (dfsn[i] == 0) dfs(i);
    }

    bool ans = 1;
    for (int i = 1; i <= n; ++i) {
      if (sn[2 * i] == sn[2 * i - 1]) {
        ans = 0;
        break;
      }
    }

    cout << "Scenario #" << i + 1 << ":\n";
    if (ans) cout << "No suspicious bugs found!\n\n";
    else cout << "Suspicious bugs found!\n\n";
  }
}