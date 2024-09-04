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

int d[305][305][305];
vector<tuple<int, int, int>> edge;
int main() {
  fastio;
  int n, m, u, v, c;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> d[0][i][j];
      if (i != j && d[0][i][j] == 0) d[0][i][j] = INF;
    }
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[k][i][j] = min(d[k - 1][i][k] + d[k - 1][k][j], d[k - 1][i][j]);
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    cin >> c >> u >> v;
    int ans = d[c - 1][u][v];
    if (ans >= INF) cout << "-1\n";
    else cout << ans << "\n";
  }
}