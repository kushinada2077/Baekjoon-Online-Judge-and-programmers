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

const int _size = 1 << 17;
int seg[_size << 1];
vector<pair<int, int>> coor;
void init() {
  fill(seg, seg + (_size << 1), 0);
  coor.clear();
}
void update(int i, int x) {
  i += _size;
  seg[i] += x;
  while (i > 1) {
    i >>= 1;
    seg[i] = seg[2 * i] + seg[2 * i + 1];
  }
}
int sum(int i, int st, int en, int l, int r) {
  if (r <= st || en <= l) return 0;
  if (l <= st && en <= r) return seg[i];
  int mid = (st + en) / 2;
  return sum(2 * i, st, mid, l, r) + sum(2 * i + 1, mid, en, l, r);
}
int main() {
  fastio;
  int t, x, y, n;
  cin >> t;
  while (t--) {
    init();
    vector<int> uni;
    ll ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      coor.pb({x, y});
      uni.pb(y);
    }
    sort(all(uni));
    uni.erase(unique(all(uni)), uni.end());
    for (int i = 0; i < n; ++i) {
      coor[i].Y = -(lower_bound(all(uni), coor[i].Y) - uni.begin());
    }
    sort(all(coor));
    for (auto [x, y] : coor) {
      y *= -1;
      int res = sum(1, 0, _size, y, _size);
      update(y, 1);
      ans += 1ll * res;
    }
    cout << ans << "\n";
  }
}