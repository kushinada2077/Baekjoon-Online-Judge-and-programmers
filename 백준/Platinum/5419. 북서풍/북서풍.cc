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

const int _size = 1 << 17;
int seg[_size << 1];
int sum(int idx, int st, int en, int l, int r) {
  if (en <= l || r <= st) return 0;
  if (l <= st && en <= r) return seg[idx];
  int mid = (st + en) / 2;
  return sum(idx << 1, st, mid, l, r) + sum(idx << 1 | 1, mid, en, l, r);
}
void update(int idx, int x) {
  idx += _size;
  seg[idx] += x;
  while (idx > 1) {
    idx >>= 1;
    seg[idx] = seg[idx << 1] + seg[idx << 1 | 1];
  }
}
int main() {
  fastio;
  int t, n, x, y;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<pair<int, int>> coor;
    vector<int> comp;
    fill(seg, seg + (_size << 1), 0);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      coor.pb({x, -y});
      comp.pb(y);
    }
    sort(all(comp));
    comp.erase(unique(all(comp)), comp.end());
    sort(all(coor));
    for (int i = 0; i < n; ++i) coor[i].Y = lower_bound(all(comp), -coor[i].Y) - comp.begin();
    for (auto [x, y] : coor) {
      ans += 1ll * sum(ROOT, 0, _size, y, _size);
      update(y, 1);
    }
    cout << ans << "\n";
  }
}