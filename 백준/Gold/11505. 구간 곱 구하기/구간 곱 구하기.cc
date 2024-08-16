#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
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
#define ROOT 1
using ll = long long;
using namespace std;

const int MOD = 1e9 + 7;
int a, b, c, n, m, k, _size = 1;
vector<int> seg(3000000, 1);
void construct() {
  for (int i = _size - 1; i != 0; --i) seg[i] = (1ll * seg[2 * i] * seg[2 * i + 1]) % MOD;
}
int tot(int idx, int st, int en, int l, int r) {
  if (en <= l || r <= st) return 1;
  if (l <= st && en <= r) return seg[idx];
  int mid = (st + en) / 2;
  return (1ll * tot(idx * 2, st, mid, l, r) * tot(idx * 2 + 1, mid, en, l, r)) % MOD;
}
void update(int idx, int val) {
  idx += _size;
  seg[idx] = val;
  while (idx > 1) {
    idx >>= 1;
    seg[idx] = (1ll * seg[idx * 2] * seg[idx * 2 + 1]) % MOD;
  }
}
int main() {
  fastio;
  cin >> n >> m >> k;
  while (_size < n) _size <<= 1;
  for (int i = 0; i < n; ++i) cin >> seg[i + _size];
  construct();
  for (int i = 0; i < m + k; ++i) {
    cin >> a >> b >> c;
    if (a == 1) update(b - 1, c);
    else cout << tot(1, 0, _size, b - 1, c) << "\n";
  }
}