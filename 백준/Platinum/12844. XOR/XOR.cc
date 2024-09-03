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

const int _size = 1 << 19;
ll seg[_size << 1], lazy[_size << 1];

void construct() {
  for (int i = _size - 1; i != 0; --i) seg[i] = seg[i << 1] ^ seg[i << 1 | 1];
}
void propagate(int node, int st, int en) {
  if (lazy[node]) {
    if (node < _size) {
      lazy[node << 1] ^= lazy[node];
      lazy[node << 1 | 1] ^= lazy[node];
    } else seg[node] ^= lazy[node];
    lazy[node] = 0;
  }
}
ll sum(int node, int st, int en, int l, int r) {
  propagate(node, st, en);
  if (en <= l || r <= st) return 0;
  if (l <= st && en <= r) return seg[node];
  int mid = (st + en) / 2;
  return sum(node << 1, st, mid, l, r) ^ sum(node << 1 | 1, mid, en, l, r);
}
void add(int node, int st, int en, int l, int r, ll x) {
  propagate(node, st, en);
  if (en <= l || r <= st) return;
  if (l <= st && en <= r) {
    lazy[node] ^= x;
    propagate(node, st, en);
    return;
  }
  int mid = (st + en) / 2;
  add(node << 1, st, mid, l, r, x);
  add(node << 1 | 1, mid, en, l, r, x);
  seg[node] = seg[node << 1] ^ seg[node << 1 | 1];
}
int main() {
  fastio;
  int n, m, a, b, c;
  ll d;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> seg[i + _size];
  cin >> m;
  construct();
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    if (b > c) swap(b, c);
    if (a == 1) {
      cin >> d;
      add(ROOT, 0, _size, b, c + 1, d);
    } else cout << sum(ROOT, 0, _size, b, c + 1) << "\n";
  }
}