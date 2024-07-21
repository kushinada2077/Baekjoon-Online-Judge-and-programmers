#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
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

int n, d, v, u, c;

int main() {
  fastio;
  cin >> n >> d;
  int ans = d;
  vector<tuple<int, int, int>> r;
  for_in(n) {
    cin >> v >> u >> c;
    if (u - v < c || u > d) continue;
    r.pb({v, u, c});
  }
  sort(all(r));
  n = si(r);
  for (int i = 0; i < (1 << n); ++i) {
    vector<tuple<int, int, int>> path;
    int cur = 0, cnt = 0;
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) path.pb(r[j]);
    }
    for (auto [v, u, c] : path) {
      if (cur <= v) {
        cnt += v - cur + c;
        cur = u;
      }
    }
    cnt += d - cur;
    if (cnt) ans = min(ans, cnt);
  }
  cout << ans << "\n";
}