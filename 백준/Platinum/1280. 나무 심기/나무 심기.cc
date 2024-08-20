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

const int M = 1e9 + 7, _size = 1 << 18;
ll seg[2][_size << 1];  // [0] 갯수 [1] 거리 합
void update(int i, ll x) {
  i += _size;
  seg[0][i] += 1;
  seg[1][i] += x;
  while (i > 1) {
    i >>= 1;
    seg[0][i] = seg[0][2 * i] + seg[0][2 * i + 1];
    seg[1][i] = seg[1][2 * i] + seg[1][2 * i + 1];
  }
}
pair<ll, ll> sum(int i, int st, int en, int l, int r) {
  if (r <= st || en <= l) return {0, 0};
  if (l <= st && en <= r) return {seg[0][i], seg[1][i]};
  int mid = (st + en) / 2;
  auto [l1, l2] = sum(2 * i, st, mid, l, r);
  auto [r1, r2] = sum(2 * i + 1, mid, en, l, r);
  return {l1 + r1, l2 + r2};
}

int main() {
  fastio;
  int n;
  ll x;
  cin >> n >> x;
  update(x, x);
  ll ans = 1;
  for (int i = 2; i <= n; ++i) {
    cin >> x;
    auto [l_cnt, l_tot] = sum(1, 0, _size, 0, x);
    auto [r_cnt, r_tot] = sum(1, 0, _size, x + 1, _size);
    ll r1 = (x * l_cnt - l_tot) % M, r2 = (r_tot - r_cnt * x) % M, r = (r1 + r2) % M;
    update(x, x);
    ans = (ans * r) % M;
  }
  cout << ans << "\n";
}