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

vector<vector<int>> d(405, vector<int>(405, INF));
int main() {
  fastio;
  int n, m, u, v, b, k;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> b;
    if (!b) {
      d[u][v] = 0;
      d[v][u] = 1;
    } else d[u][v] = d[v][u] = 0;
  }
  cin >> k;
  for (int i = 1; i <= n; ++i) d[i][i] = 0;
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    cin >> u >> v;
    cout << d[u][v] << "\n";
  }
}