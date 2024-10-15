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

inline int oppo(int v) { return v % 2 ? v + 1 : v - 1; }
const int MX = 10001;
int n, m, cnt, SN;
int dfsn[MX << 1], sccNum[MX << 1];
bool finished[MX << 1];
vector<int> adj[MX << 1], scc[MX << 1];
stack<int> s;
int dfs(int cur) {
  int res = dfsn[cur] = ++cnt;
  s.push(cur);

  for (auto& nxt : adj[cur]) {
    if (!dfsn[nxt]) res = min(res, dfs(nxt));
    else if (!finished[nxt]) res = min(res, dfsn[nxt]);
  }

  if (dfsn[cur] == res) {
    while (1) {
      int v = s.top();
      s.pop();
      finished[v] = 1;
      sccNum[v] = SN;
      if (v == cur) break;
    }
    SN++;
  }

  return res;
}
int main() {
  fastio;
  cin >> n >> m;
  for (int a, b; m--;) {
    cin >> a >> b;
    a = a > 0 ? 2 * a : -a * 2 - 1;
    b = b > 0 ? 2 * b : -b * 2 - 1;
    adj[oppo(a)].pb(b);
    adj[oppo(b)].pb(a);
  }

  for (int i = 1; i <= 2 * n; ++i) {
    if (dfsn[i] == 0) dfs(i);
  }

  for (int i = 1; i <= n; ++i) {
    if (sccNum[2 * i] == sccNum[2 * i - 1]) {
      cout << "0\n";
      return 0;
    }
  }

  cout << "1\n";
}