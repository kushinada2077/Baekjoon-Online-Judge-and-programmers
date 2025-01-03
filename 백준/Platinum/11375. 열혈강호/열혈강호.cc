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

const int MX = 3000;

int n, m, A[MX], B[MX];
bool vis[MX];
vector<int> adj[MX];
void init() {
  for (int i = 0; i < MX; ++i) {
    A[i] = B[i] = -1;
  }
}

bool dfs(int cur) {
  vis[cur] = 1;
  for (auto nxt : adj[cur]) {
    if (B[nxt] == -1 || !vis[B[nxt]] && dfs(B[nxt])) {
      A[cur] = nxt;
      B[nxt] = cur;
      return 1;
    }
  }

  return 0;
}
int main() {
  fastio;

  init();
  cin >> n >> m;
  for (int u, v, x, i = 0; i < n; ++i) {
    cin >> x;
    u = 2 * i;
    for (int j = 0; j < x; ++j) {
      cin >> v;
      v = 2 * v + 1;
      adj[u].pb(v);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    fill(vis, vis + MX, 0);
    if (dfs(2 * i)) ans++;
  }
  cout << ans << "\n";
}