#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

int main() {
  fastio;
  int n, m, x, y;
  cin >> n >> m;
  vector<pair<int, int>> a;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    a.pb({x, y});
  }

  int br = 1 << m, ans = -1;
  for (int i = 0; i < br; ++i) {
    int sum = 0, day = 0;
    for (int j = 0; j < m; ++j) {
      if (i & (1 << j)) {
        day += a[j].X;
        sum += a[j].Y;
      }
      if (day > n) break;
    }
    if (day <= n) ans = max(ans, sum);
  }
  cout << ans << "\n";
}