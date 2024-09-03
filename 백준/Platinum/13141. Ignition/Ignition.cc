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

int d[205][205];
vector<tuple<int, int, int>> edge;
int main() {
  fastio;
  int n, m, u, v, c;
  cin >> n >> m;
  for (int i = 0; i < 205; ++i) fill(d[i], d[i] + 205, INF);
  for (int i = 1; i <= n; ++i) d[i][i] = 0;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> c;
    if (d[v][u] > c) d[v][u] = d[u][v] = c;
    edge.pb({c, u, v});
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
      }
    }
  }

  double ans = INF;
  cout << fixed;
  cout.precision(1);
  for (int i = 1; i <= n; ++i) {
    double tmp = -1;
    for (int j = 0; j < m; ++j) {
      auto [c, u, v] = edge[j];
      if (tmp < (d[i][u] + d[i][v] + c) / (double)2) tmp = (d[i][u] + d[i][v] + c) / (double)2;
    }
    ans = min(tmp, ans);
  }
  cout << ans << "\n";
}