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

int n, _size = 1, m, q, l, r, c;
ll seg[300000];

ll sum(int idx, int st, int en, int l, int r) {
  if (en <= l || r <= st) return 0;
  if (l <= st && en <= r) return seg[idx];
  int mid = (st + en) / 2;
  return sum(2 * idx, st, mid, l, r) + sum(2 * idx + 1, mid, en, l, r);
}
void update(int idx, int val) {
  idx += _size;
  seg[idx] += 1ll * val;
  while (idx > 1) {
    idx >>= 1;
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
  }
}
int main() {
  fastio;
  int n, pre = 0, x;
  cin >> n;
  while (_size < n) _size <<= 1;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    seg[i + _size] = x - pre;
    pre = x;
  }
  for (int i = _size - 1; i != 0; --i) seg[i] = seg[2 * i] + seg[2 * i + 1];
  cin >> m;
  while (m--) {
    cin >> q;
    if (q == 1) {
      cin >> l >> r >> c;
      update(l - 1, c);
      if (r < n) update(r, -c);
    } else {
      cin >> c;
      cout << sum(1, 0, _size, 0, c) << "\n";
    }
  }
}