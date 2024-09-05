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
int t, n, k, q, a, b;
int seg[_size << 1][2];
void construct() {
  for (int i = _size - 1; i != 0; --i) {
    seg[i][0] = min(seg[i << 1][0], seg[i << 1 | 1][0]);
    seg[i][1] = max(seg[i << 1][1], seg[i << 1 | 1][1]);
  }
}
void init() {
  for (int i = _size; i < 2 * _size; ++i) {
    if (i < _size + n) seg[i][0] = seg[i][1] = i - _size;
    else {
      seg[i][0] = INF;
      seg[i][1] = -1;
    }
  }
  construct();
}
void update(int node, int x) {
  node += _size;
  seg[node][0] = seg[node][1] = x;
  while (node > 1) {
    node >>= 1;
    seg[node][0] = min(seg[node << 1][0], seg[node << 1 | 1][0]);
    seg[node][1] = max(seg[node << 1][1], seg[node << 1 | 1][1]);
  }
}
pair<int, int> sum(int node, int st, int en, int l, int r) {
  if (en <= l || r <= st) return {INF, -1};
  if (l <= st && en <= r) return {seg[node][0], seg[node][1]};
  int mid = (st + en) / 2;
  auto [mn1, mx1] = sum(node << 1, st, mid, l, r);
  auto [mn2, mx2] = sum(node << 1 | 1, mid, en, l, r);
  return {min(mn1, mn2), max(mx1, mx2)};
}
int main() {
  fastio;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    init();
    for (int i = 0; i < k; ++i) {
      cin >> q >> a >> b;
      if (!q) {
        int tmp = seg[_size + a][0];
        update(a, seg[_size + b][0]);
        update(b, tmp);
      } else {
        auto [l, r] = sum(ROOT, 0, _size, a, b + 1);
        if (l == a && r == b) cout << "YES\n";
        else cout << "NO\n";
      }
    }
  }
}