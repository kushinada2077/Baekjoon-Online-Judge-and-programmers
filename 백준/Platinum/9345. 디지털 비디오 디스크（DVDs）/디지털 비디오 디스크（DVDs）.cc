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

int _size, n, m;
ll seg[2][300000];
void construct() {
  for (int i = _size - 1; i != 0; --i) {
    seg[0][i] = max(seg[0][2 * i], seg[0][2 * i + 1]);
    seg[1][i] = min(seg[1][2 * i], seg[1][2 * i + 1]);
  }
}
void init() {
  cin >> n >> m;
  _size = 1;
  while (_size < n) _size <<= 1;
  fill(seg[0], seg[0] + 300000, -1);
  fill(seg[1], seg[1] + 300000, 0x3f3f3f3f);
  for (int i = _size; i < _size + n; ++i) seg[0][i] = seg[1][i] = i - _size;
  construct();
}
ll get_mx(int idx, int st, int en, int l, int r) {
  if (en <= l || r <= st) return -1;
  if (l <= st && en <= r) return seg[0][idx];
  int mid = (st + en) / 2;
  return max(get_mx(2 * idx, st, mid, l, r), get_mx(2 * idx + 1, mid, en, l, r));
}
ll get_mn(int idx, int st, int en, int l, int r) {
  if (en <= l || r <= st) return 0x3f3f3f3f;
  if (l <= st && en <= r) return seg[1][idx];
  int mid = (st + en) / 2;
  return min(get_mn(2 * idx, st, mid, l, r), get_mn(2 * idx + 1, mid, en, l, r));
}
void update(int idx, int val) {
  idx += _size;
  seg[0][idx] = seg[1][idx] = 1ll * val;
  while (idx > 1) {
    idx >>= 1;
    seg[0][idx] = max(seg[0][2 * idx], seg[0][2 * idx + 1]);
    seg[1][idx] = min(seg[1][2 * idx], seg[1][2 * idx + 1]);
  }
}
int main() {
  fastio;
  int t, q, a, b;
  cin >> t;
  while (t--) {
    init();
    while (m--) {
      cin >> q >> a >> b;
      if (q == 0) {
        if (a == b) continue;
        int tmp = seg[0][a + _size];
        update(a, seg[0][b + _size]);
        update(b, tmp);
      } else {
        int mx = get_mx(1, 0, _size, a, b + 1), mn = get_mn(1, 0, _size, a, b + 1);
        if (mx == b && mn == a) cout << "YES\n";
        else cout << "NO\n";
      }
    }
  }
}