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

const int _size = (1 << 20);
int seg[_size << 1];

void update(int idx, int val) {
  idx += _size;
  seg[idx] = val;
  while (idx > 1) {
    idx >>= 1;
    seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
  }
}
int mx(int idx, int st, int en, int l, int r) {
  if (en <= l || r <= st) return 0;
  if (l <= st && en <= r) return seg[idx];
  int mid = (st + en) / 2;
  return max(mx(2 * idx, st, mid, l, r), mx(2 * idx + 1, mid, en, l, r));
}
int main() {
  fastio;
  int n, x;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    a.pb({x, -i});
  }
  sort(all(a));
  for (auto& [x, i] : a) {
    i *= -1;
    int len = mx(1, 0, _size, 0, i + 1) + 1;
    if (len > seg[_size + i]) update(i, len);
  }
  cout << seg[1] << "\n";
}