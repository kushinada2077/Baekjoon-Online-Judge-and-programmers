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
int seg[_size << 1];
void update(int i, int x) {
  i += _size;
  seg[i] = x;
  while (i > 1) {
    i >>= 1;
    seg[i] = seg[2 * i] + seg[2 * i + 1];
  }
}
int sum(int i, int st, int en, int l, int r) {
  if (r <= st || en <= l) return 0;
  if (l <= st && en <= r) return seg[i];
  int mid = (st + en) / 2;
  return sum(2 * i, st, mid, l, r) + sum(2 * i + 1, mid, en, l, r);
}
int main() {
  fastio;
  int n, x;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    a.pb({x, i});
    seg[i + _size] = 1;
  }
  sort(all(a));
  for (int i = _size - 1; i != 0; --i) seg[i] = seg[2 * i] + seg[2 * i + 1];
  int l = 0, r = n - 1;
  for (int i = 0; i < n; ++i) {
    int x, idx;
    tie(x, idx) = a[i];
    if (i & 1) {
      tie(x, idx) = a[n - 1 - i / 2];
      cout << sum(1, 0, _size, idx + 1, _size) << "\n";
    } else {
      tie(x, idx) = a[i / 2];
      cout << sum(1, 0, _size, 0, idx) << "\n";
    }
    update(idx, 0);
  }
}