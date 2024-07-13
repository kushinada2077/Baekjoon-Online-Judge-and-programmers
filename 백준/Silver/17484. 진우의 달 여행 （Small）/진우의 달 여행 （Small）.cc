#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

const int IMPOSSIBLE = 0x3f3f3f3f;
int d[10][10][3], n, m;
bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }
int f(vector<vector<int>>& a, int x, int y, int k) {
  if (OOB(x, y)) return IMPOSSIBLE;
  if (x == 0) return a[x][y];
  if (d[x][y][k] != IMPOSSIBLE) return d[x][y][k];
  int ret = IMPOSSIBLE;
  for (int i = 0; i < 3; ++i) {
    if (i == k) continue;
    ret = min(ret, f(a, x - 1, y + i - 1, i) + a[x][y]);
  }
  d[x][y][k] = ret;
  return ret;
}
int main() {
  fastio;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (auto& i : a)
    for (auto& j : i) cin >> j;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) fill(d[i][j], d[i][j] + 3, IMPOSSIBLE);
  }
  for (int i = 0; i < m; ++i)
    for (int k = 0; k < 3; ++k) f(a, n - 1, i, k);
  int ans = IMPOSSIBLE;
  for (int j = 0; j < m; ++j) {
    for (int k = 0; k < 3; ++k) {
      ans = min(ans, d[n - 1][j][k]);
    }
  }
  cout << ans << "\n";
}