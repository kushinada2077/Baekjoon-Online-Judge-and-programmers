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

vector<vector<int>> d(105, vector<int>(105, INF)), nxt(105, vector<int>(105, 0));
int main() {
  fastio;
  int n, m, u, v, c;
  cin >> n >> m;
  for (int i = 0; i <= m; ++i) {
    cin >> u >> v >> c;
    if (d[u][v] > c) {
      d[u][v] = c;
      nxt[u][v] = v;
    }
  }
  for (int i = 1; i <= n; ++i) d[i][i] = 0;
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (d[i][j] > d[i][k] + d[k][j]) {
          d[i][j] = d[i][k] + d[k][j];
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (d[i][j] == INF) cout << "0 ";
      else cout << d[i][j] << " ";
    }
    cout << "\n";
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      vector<int> path;
      int cur = i;
      while (nxt[cur][j]) {
        path.pb(cur);
        cur = nxt[cur][j];
      }
      path.pb(j);
      if (si(path) == 1) cout << "0\n";
      else {
        cout << si(path) << " ";
        for (auto& v : path) cout << v << " ";
        cout << "\n";
      }
    }
  }
}