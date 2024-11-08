#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
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
using TP = tuple<int, int, int>;
using P = pair<int, int>;

const int MX = 4000;

int t, n, m, A[MX], B[MX];
set<int> aSet;
bool vis[MX];
vector<int> adj[MX];

void init() {
  aSet.clear();
  for (int i = 0; i < MX; ++i) {
    A[i] = B[i] = -1;
    adj[i].clear();
  }
}

bool dfs(int a) {
  vis[a] = 1;
  for (int b : adj[a]) {
    if (B[b] == -1 || !vis[B[b]] && dfs(B[b])) {
      A[a] = b;
      B[b] = a;
      return 1;
    }
  }

  return 0;
}

int main() {
  fastio;
  cin >> t;
  while (t--) {
    init();
    cin >> n >> m;

    for (int u, v, i = 0; i < m; ++i) {
      cin >> u >> v;
      aSet.insert(2 * u);
      adj[2 * u].pb(2 * v + 1);
    }

    int ans = 0;

    for (auto a : aSet) {
      fill(vis, vis + MX, 0);
      if (dfs(a)) ans++;
    }

    cout << ans << "\n";
  }
}