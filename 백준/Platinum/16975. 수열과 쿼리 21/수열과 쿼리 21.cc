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
ll seg[_size << 1];
// d[i] = a[i] - a[i - 1], d[0] = 0
void update(int l, int r, ll x) {
  l += _size;
  r += _size + 1;
  seg[l] += x;
  seg[r] -= x;
  while (l > 1) {
    l >>= 1;
    seg[l] = seg[2 * l] + seg[2 * l + 1];
  }
  while (r > 1) {
    r >>= 1;
    seg[r] = seg[2 * r] + seg[2 * r + 1];
  }
}
ll sum(int i, int st, int en, int l, int r) {
  if (en <= l || r <= st) return 0;
  if (l <= st && en <= r) return seg[i];
  int mid = (st + en) / 2;
  return sum(2 * i, st, mid, l, r) + sum(2 * i + 1, mid, en, l, r);
}
int main() {
  fastio;
  int n, m, a, b, c, pre = 0, x;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    seg[i + _size] = x - pre;
    pre = x;
  }
  for (int i = _size - 1; i != 0; --i) seg[i] = seg[2 * i] + seg[2 * i + 1];
  cin >> m;
  while (m--) {
    cin >> a;
    if (a == 1) {
      cin >> b >> c >> x;
      update(b - 1, c - 1, x);
    } else {
      cin >> x;
      cout << sum(1, 0, _size, 0, x) << "\n";
    }
  }
}