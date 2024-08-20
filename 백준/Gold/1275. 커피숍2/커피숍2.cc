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

const int _size = (1 << 17);
ll seg[_size << 1];

void update(int idx, ll val) {
  idx += _size;
  seg[idx] = val;
  while (idx > 1) {
    idx >>= 1;
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
  }
}
ll sum(int idx, int st, int en, int l, int r) {
  if (en <= l || r <= st) return 0;
  if (l <= st && en <= r) return seg[idx];
  int mid = (st + en) / 2;
  return sum(2 * idx, st, mid, l, r) + sum(2 * idx + 1, mid, en, l, r);
}
int main() {
  fastio;
  int N, Q, x, y, a, b;
  cin >> N >> Q;
  for (int i = 0; i < N; ++i) cin >> seg[_size + i];
  for (int i = _size - 1; i != 0; --i) seg[i] = seg[2 * i] + seg[2 * i + 1];
  while (Q--) {
    cin >> x >> y >> a >> b;
    if (x > y) swap(x, y);
    cout << sum(1, 0, _size, x - 1, y) << "\n";
    update(a - 1, b);
  }
}