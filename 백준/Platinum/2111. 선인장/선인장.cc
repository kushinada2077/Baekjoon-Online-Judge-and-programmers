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

const int MX = 20001;
int n, m, u, v, x, cnt, BN, cN;
int dfsn[MX], bccSize[MX];
unordered_set<int> bccMember[MX];
vector<int> adj[MX];
stack<pair<int, int>> s;
vector<int> ans = {1};

vector<int> mul(vector<int>& A, int B) {
  int asz = A.size(), rsz = asz, p = 0, n;
  vector<int> result(rsz);
  while (B) {
    n = B % 10;
    B /= 10;
    result.resize(++rsz);
    for (int i = 0; i < asz; i++) result[i + p] += A[i] * n;
    p++;
  }

  for (int i = 0, n; i < rsz; i++) {
    n = result[i] % 10;
    result[i + 1] += result[i] / 10;
    result[i] = n;
  }

  if (!result[rsz - 1]) result.resize(--rsz);

  return result;
}

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
          auto& [u, v] = s.top();
          s.pop();
          bccMember[BN].insert(u);
          bccMember[BN].insert(v);
          bccSize[BN]++;
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
    cin >> x >> u;
    for (int j = 0; j < x - 1; ++j) {
      cin >> v;
      adj[u].pb(v);
      adj[v].pb(u);
      u = v;
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (dfsn[i] == 0) {
      dfs(i);
      cN++;
    }
  }

  if (cN > 1) {
    cout << "0\n";
    return 0;
  }

  for (int i = 0; i < BN; ++i) {
    if (bccSize[i] < 3) continue;

    if (si(bccMember[i]) != bccSize[i]) {
      cout << "0\n";
      return 0;
    }

    int vn = bccSize[i] + 1;
    ans = mul(ans, vn);
  }

  for (int i = si(ans) - 1; i >= 0; --i) cout << ans[i];
  cout << "\n";
}