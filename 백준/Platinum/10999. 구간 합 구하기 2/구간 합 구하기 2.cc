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
ll seg[_size << 1], lazy[_size << 1];

void propagate(int node, int s, int e) {
  if (lazy[node]) {
    if (node < _size) {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    seg[node] += lazy[node] * (e - s);
    lazy[node] = 0;
  }
}
void add(int node, int s, int e, int l, int r, ll x) {
  propagate(node, s, e);
  if (e <= l || r <= s) return;
  if (l <= s && e <= r) {
    lazy[node] += x;
    propagate(node, s, e);
    return;
  }
  int mid = (s + e) / 2;
  add(2 * node, s, mid, l, r, x);
  add(2 * node + 1, mid, e, l, r, x);
  seg[node] = seg[2 * node] + seg[2 * node + 1];
}
ll sum(int node, int s, int e, int l, int r) {
  propagate(node, s, e);
  if (e <= l || r <= s) return 0;
  if (l <= s && e <= r) return seg[node];
  int mid = (s + e) / 2;
  return sum(2 * node, s, mid, l, r) + sum(2 * node + 1, mid, e, l, r);
}
int main() {
  fastio;
  int n, m, k, a, b, c;
  ll d;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) cin >> seg[i + _size];
  for (int i = _size - 1; i != 0; --i) seg[i] = seg[2 * i] + seg[2 * i + 1];
  for (int i = 0; i < m + k; ++i) {
    cin >> a >> b >> c;
    if (a == 1) {
      cin >> d;
      add(1, 0, _size, b - 1, c, d);
    } else {
      cout << sum(1, 0, _size, b - 1, c) << "\n";
    }
  }
}