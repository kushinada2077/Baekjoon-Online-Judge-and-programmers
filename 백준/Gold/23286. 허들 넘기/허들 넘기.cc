#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

int d[305][305], nxt[305][305];
int main() {
  fastio;
  int n, m, t, s, e, u, v, h;
  cin >> n >> m >> t;

  for (int i = 0; i < 305; ++i) fill(d[i], d[i] + 305, INF);
  for (int i = 1; i <= n; ++i) d[i][i] = 0;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> h;
    if (d[u][v] > h) d[u][v] = h;
    nxt[u][v] = v;
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
      }
    }
  }

  while (t--) {
    cin >> s >> e;
    if (d[s][e] == INF) cout << "-1\n";
    else cout << d[s][e] << "\n";
  }
}