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

const int _size = 1 << 20;
int n, Q, p, q, x, c;
ll seg[3000000];

void update(int idx, ll delta) {
  idx += _size;
  seg[idx] += delta;
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
  cin >> n >> Q;
  while (Q--) {
    cin >> c;
    if (c == 1) {
      cin >> p >> x;
      update(p, x);
    } else {
      cin >> p >> q;
      cout << sum(1, 0, _size, p, q + 1) << "\n";
    }
  }
}