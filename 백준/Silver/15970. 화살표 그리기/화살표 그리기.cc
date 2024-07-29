#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <tuple>
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
  int n, x, y;
  cin >> n;
  vector<pair<int, int>> arr;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    arr.pb({x, y});
  }
  sort(all(arr));

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int mn_dist = 0x3f3f3f3f;
    for (int j = 0; j < n; ++j) {
      if (i == j || arr[i].Y != arr[j].Y) continue;
      mn_dist = min(mn_dist, abs(arr[i].X - arr[j].X));
    }
    ans += (ll)mn_dist;
  }
  cout << ans << "\n";
}