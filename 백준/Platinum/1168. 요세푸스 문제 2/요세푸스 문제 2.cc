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

int _size = (1 << 20), seg[3000000];
void update(int idx, int delta) {
  idx += _size;
  seg[idx] += delta;
  while (idx > 1) {
    idx >>= 1;
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
  }
}
int pth(int idx, int st, int en, int p) {
  if (st + 1 == en) return st;
  int mid = (st + en) / 2;
  if (seg[2 * idx] >= p) return pth(2 * idx, st, mid, p);
  return pth(2 * idx + 1, mid, en, p - seg[2 * idx]);
}
int sum(int idx, int st, int en, int l, int r) {
  if (en <= l || r <= st) return 0;
  if (l <= st && en <= r) return seg[idx];
  int mid = (st + en) / 2;
  return sum(2 * idx, st, mid, l, r) + sum(2 * idx + 1, mid, en, l, r);
}
int main() {
  fastio;
  int n, k, cur, len;
  cin >> n >> k;
  cur = k;
  len = n;
  for (int i = _size + 1; i < _size + 1 + n; ++i) seg[i] = 1;
  for (int i = _size - 1; i != 0; --i) seg[i] = seg[2 * i] + seg[2 * i + 1];
  cout << "<";
  for (int i = 0; i < n; ++i) {
    int res = pth(1, 0, _size, cur);
    int tot = sum(1, 0, _size, 0, _size);
    int r = sum(1, 0, _size, res + 1, _size);
    update(res, -1);
    len--;
    cout << res;
    if (i == n - 1) break;
    cout << ", ";
    if (r >= k) cur += k - 1;
    else cur = (k - r - 1) % len + 1;
  }
  cout << ">\n";
}