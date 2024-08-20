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

int n, t, x, _size = (1 << 21), seg[5000000];
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
  int mid = (st + en) / 2;
  int l = seg[2 * idx];
  if (k <= l) return kth(2 * idx, st, mid, k);
  return kth(2 * idx + 1, mid, en, k - l);
}
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t >> x;
    if (t == 1) update(x, 1);
    else {
      x = kth(1, 0, _size, x);
      cout << x << "\n";
      update(x, -1);
    }
  }
}