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

vector<vector<int>> dist(105, vector<int>(105, INF));
int main() {
  fastio;
  int n, m, u, v, c;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> c;
    dist[u][v] = min(dist[u][v], c);
  }
  for (int i = 1; i <= n; ++i) dist[i][i] = 0;

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (dist[i][j] == INF) cout << "0 ";
      else cout << dist[i][j] << " ";
    }
    cout << "\n";
  }
}