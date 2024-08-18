#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int main() {
  fastio;
  int n, m, x, x1, y1, x2, y2, r[1025][1025];
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> x;
      r[i][j] = r[i - 1][j] + r[i][j - 1] - r[i - 1][j - 1] + x;
    }
  }
  while (m--) {
    cin >> x1 >> y1 >> x2 >> y2;
    ll ans = r[x2][y2] - r[x2][y1 - 1] - r[x1 - 1][y2] + r[x1 - 1][y1 - 1];
    cout << ans << "\n";
  }
}