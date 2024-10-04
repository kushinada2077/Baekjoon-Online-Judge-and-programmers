#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
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

const int _size = 1 << 20;
int n, m, k;
ll a, b, c, d;
ll seg[_size << 1], lazy[_size << 1];

void construct() {
  for (int i = _size - 1; i != 0; --i) {
    seg[i] = seg[i << 1] + seg[i << 1 | 1];
  }
}
void propagate(int node, int st, int en) {
  if (lazy[node]) {
    if (node < _size) {
      lazy[node << 1] += lazy[node];
      lazy[node << 1 | 1] += lazy[node];
    }
    seg[node] += lazy[node] * (en - st);
    lazy[node] = 0;
  }
}
void update(int node, int st, int en, int l, int r, ll x) {
  propagate(node, st, en);
  if (r <= st || en <= l) return;
  if (l <= st && en <= r) {
    lazy[node] += x;
    propagate(node, st, en);
    return;
  }
  int mid = (st + en) / 2;
  update(node << 1, st, mid, l, r, x);
  update(node << 1 | 1, mid, en, l, r, x);
  seg[node] = seg[node << 1] + seg[node << 1 | 1];
}
ll sum(int node, int st, int en, int l, int r) {
  propagate(node, st, en);
  if (r <= st || en <= l) return 0;
  if (l <= st && en <= r) return seg[node];
  int mid = (st + en) / 2;
  return sum(node << 1, st, mid, l, r) + sum(node << 1 | 1, mid, en, l, r);
}
int main() {
  fastio;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    cin >> seg[_size + i];
  }
  construct();
  for (int i = 0; i < m + k; ++i) {
    cin >> a >> b >> c;
    if (a == 1) {
      cin >> d;
      update(ROOT, 0, _size, b - 1, c, d);
    } else {
      cout << sum(ROOT, 0, _size, b - 1, c) << "\n";
    }
  }
}