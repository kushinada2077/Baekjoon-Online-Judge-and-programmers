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

int A[MX], B[MX], n, m, k;
bool vis[MX];
vector<int> adj[MX];

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
  fill(B, B + MX, -1);
  cin >> n >> m >> k;
  for (int x, u1, u2, v, i = 0; i < n; ++i) {
    u1 = 3 * i;
    u2 = u1 + 1;
    cin >> x;
    for (int j = 0; j < x; ++j) {
      cin >> v;
      v = 3 * v + 2;
      adj[u1].pb(v);
      adj[u2].pb(v);
    }
  }

  int ans = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    fill(vis, vis + MX, 0);
    if (dfs(3 * i)) ans++;
  }
  for (int i = 0; i < n; ++i) {
    fill(vis, vis + MX, 0);
    if (dfs(3 * i + 1)) cnt++;
    if (cnt == k) break;
  }

  cout << ans + cnt << "\n";
}