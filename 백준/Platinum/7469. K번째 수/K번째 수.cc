#include <algorithm>
#include <iostream>
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
vector<int> seg[_size << 1];

void construct() {
  for (int i = _size - 1; i != 0; --i) {
    vector<int>&c = seg[i], l = seg[i << 1], r = seg[i << 1 | 1];
    c.resize(si(l) + si(r));
    for (int j = 0, p = 0, q = 0; j < si(l) + si(r); ++j) {
      if (q == si(r) || (p < si(l) && l[p] <= r[q])) c[j] = l[p++];
      else c[j] = r[q++];
    }
  }
}
int find(int node, int st, int en, int l, int r, int k) {
  if (en <= l || r <= st) return 0;
  if (l <= st && en <= r) return lower_bound(all(seg[node]), k) - seg[node].begin();
  int mid = (st + en) / 2;
  return find(node << 1, st, mid, l, r, k) + find(node << 1 | 1, mid, en, l, r, k);
}
int main() {
  fastio;
  int n, m, x, a, b, c;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    seg[i + _size].pb(x);
  }
  construct();
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    int lo = -1e9 - 1, hi = 1e9;
    while (lo + 1 < hi) {
      int mid = (lo + hi) / 2;
      if (find(ROOT, 0, _size, a - 1, b, mid) > c - 1) hi = mid;
      else lo = mid;
    }
    cout << lo << "\n";
  }
}