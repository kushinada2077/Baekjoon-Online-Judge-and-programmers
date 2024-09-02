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
  int n, x, y;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    a.pb({x, y});
  }
  sort(all(a));
  ll ans = 0;
  int l, r;
  tie(l, r) = a[0];
  for (int i = 1; i < n; ++i) {
    auto [nl, nr] = a[i];
    if (r < nl) {
      ans += r - l;
      l = nl;
      r = nr;
    } else r = max(r, nr);
  }
  ans += r - l;
  cout << ans << "\n";
}