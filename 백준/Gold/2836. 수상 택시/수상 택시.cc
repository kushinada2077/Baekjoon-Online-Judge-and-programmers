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

int main() {
  fastio;
  // freopen(PATH, "r", stdin);
  int n, m, u, v;
  cin >> n >> m;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; ++i) {
    cin >> u >> v;
    if (u > v) a.pb({v, u});
  }
  sort(all(a));
  int cx = -INF, cy = -INF;
  ll ans = 0;
  vector<int> r;
  for (int i = 0; i < si(a); ++i) {
    auto [nx, ny] = a[i];
    if (cy < nx) {
      ans += 2ll * (1ll * cy - cx);
      r.pb(cy);
      cx = nx;
      cy = ny;
    } else if (cy < ny) cy = ny;
  }
  ans += 2ll * (1ll * cy - cx);
  r.pb(cy);
  r.pb(m);
  r[0] = 0;
  for (int i = 0; i < si(r) - 1; ++i) ans += 1ll * r[i + 1] - r[i];
  cout << ans << "\n";
}