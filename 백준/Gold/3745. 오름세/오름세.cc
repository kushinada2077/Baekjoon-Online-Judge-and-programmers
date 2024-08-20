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
    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
  }
}

int mx(int i, int st, int en, int l, int r) {
  if (en <= l || r <= st) return 0;
  if (l <= st && en <= r) return seg[i];
  int mid = (st + en) / 2;
  return max(mx(2 * i, st, mid, l, r), mx(2 * i + 1, mid, en, l, r));
}

int main() {
  fastio;
  int n, x;
  while (cin >> n) {
    fill(seg, seg + (_size << 1), 0);
    vector<pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      a.pb({x, -i});
    }
    sort(all(a));
    for (auto& [x, i] : a) {
      i *= -1;
      int res = mx(1, 0, _size, 0, i) + 1;
      if (res > seg[_size + i]) update(i, res);
    }
    cout << seg[1] << "\n";
  }
}