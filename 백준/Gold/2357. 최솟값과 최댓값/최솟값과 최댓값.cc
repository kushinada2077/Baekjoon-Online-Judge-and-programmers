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

int _size = 1, seg[2][300000];
void construct() {
  for (int i = _size - 1; i != 0; --i) {
    seg[0][i] = max(seg[0][2 * i], seg[0][2 * i + 1]);
    seg[1][i] = min(seg[1][2 * i], seg[1][2 * i + 1]);
  }
}
pair<int, int> get_m(int idx, int st, int en, int l, int r) {
  if (en <= l || r <= st) return {-1, 0x3f3f3f3f};
  if (l <= st && en <= r) return {seg[0][idx], seg[1][idx]};
  int mid = (st + en) / 2;
  auto ret = get_m(idx * 2, st, mid, l, r);
  auto ret2 = get_m(idx * 2 + 1, mid, en, l, r);
  return {max(ret.X, ret2.X), min(ret.Y, ret2.Y)};
}
int main() {
  fastio;
  int n, m, a, b;
  cin >> n >> m;
  while (_size < n) _size <<= 1;
  fill(seg[0], seg[0] + 300000, -1);
  fill(seg[1], seg[1] + 300000, 0x3f3f3f3f);
  for (int i = 0; i < n; ++i) {
    cin >> seg[0][_size + i];
    seg[1][_size + i] = seg[0][_size + i];
  }
  construct();
  while (m--) {
    cin >> a >> b;
    auto [mx, mn] = get_m(1, 0, _size, a - 1, b);
    cout << mn << " " << mx << "\n";
  }
}