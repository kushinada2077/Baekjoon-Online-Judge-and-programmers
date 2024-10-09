#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
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

const int MX = 100001;
int n, m, u, v, cnt, dup, BN;
int dfsn[MX], bSize[MX];
bool chk[MX];
vector<int> adj[MX];
unordered_set<int> bcc_member[MX];
stack<pair<int, int>> s;

int dfs(int cur, int prev = -1) {
  int res = dfsn[cur] = ++cnt;

  for (auto& nxt : adj[cur]) {
    if (nxt == prev) continue;
    if (dfsn[cur] > dfsn[nxt]) s.push({cur, nxt});
    if (dfsn[nxt] > 0) res = min(res, dfsn[nxt]);
    else {
      int tmp = dfs(nxt, cur);
      res = min(res, tmp);
      if (tmp >= dfsn[cur]) {
        while (1) {
          auto [u, v] = s.top();
          s.pop();
          bcc_member[BN].insert(u);
          bcc_member[BN].insert(v);
          bSize[BN]++;
          if (u == cur && v == nxt) break;
        }
        BN++;
      }
    }
  }
  return res;
}

int main() {
  fastio;
  cin >> n >> m;
  rep(m) {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  for (int i = 1; i <= n; ++i) {
    if (dfsn[i] == 0) dfs(i);
  }

  int cntt = 0;
  for (int i = 0; i < BN; ++i) {
    if (bSize[i] < 3) continue;

    if (bSize[i] != si(bcc_member[i])) {
      cout << "Not cactus\n";
      return 0;
    }

    for (auto& u : bcc_member[i]) {
      if (chk[u]) {
        cout << "Not cactus\n";
        return 0;
      }
      chk[u] = 1;
    }
  }
  cout << "Cactus\n";
}