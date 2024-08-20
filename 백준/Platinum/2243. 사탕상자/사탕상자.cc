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
int seg[2 * _size];

void update(int idx, int delta) {
  idx += _size;
  seg[idx] += delta;
  while (idx > 1) {
    idx >>= 1;
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
  }
}
int kth(int idx, int st, int en, int k) {
  if (st + 1 == en) return st;
  int mid = (st + en) / 2, l = seg[2 * idx];
  if (k <= l) return kth(2 * idx, st, mid, k);
  return kth(2 * idx + 1, mid, en, k - l);
}
int main() {
  fastio;
  int n, a, b, c;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    if (a == 1) {
      int res = kth(1, 0, _size, b);
      update(res, -1);
      cout << res << "\n";
    } else {
      cin >> c;
      update(b, c);
    }
  }
}