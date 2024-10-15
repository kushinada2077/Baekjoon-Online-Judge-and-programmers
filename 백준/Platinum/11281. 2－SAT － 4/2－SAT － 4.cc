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
int dfsn[MX << 1], sn[MX << 1], res[MX];
bool finished[MX << 1];
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
  for (int u, v; m--;) {
    cin >> u >> v;
    u = u > 0 ? 2 * u : -u * 2 - 1;
    v = v > 0 ? 2 * v : -v * 2 - 1;
    adj[oppo(u)].pb(v);
    adj[oppo(v)].pb(u);
  }

  for (int i = 1; i <= 2 * n; ++i) {
    if (dfsn[i] == 0) dfs(i);
  }

  for (int i = 1; i <= n; ++i) {
    if (sn[2 * i] == sn[2 * i - 1]) {
      cout << "0\n";
      return 0;
    }
  }

  cout << "1\n";

  fill(res, res + MX, -1);
  int p[MX * 2];
  for (int i = 1; i <= 2 * n; ++i) {
    p[i] = i;
  }

  sort(p + 1, p + 2 * n + 1, [&](int a, int b) { return sn[a] > sn[b]; });

  for (int i = 1; i <= 2 * n; ++i) {
    int var = p[i];
    if (res[(var + 1) / 2] == -1) res[(var + 1) / 2] = var % 2;
  }

  for (int i = 1; i <= n; ++i) cout << res[i] << " ";
}