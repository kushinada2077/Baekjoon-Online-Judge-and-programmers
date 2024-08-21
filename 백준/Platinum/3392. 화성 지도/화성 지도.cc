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

const int _size = 1 << 16;
int seg[_size << 1], cnt[_size << 1];

void update(int node, int s, int e, int l, int r, int x) {
  if (e <= l || r <= s) return;
  if (l <= s && e <= r) cnt[node] += x;
  else {
    int mid = (s + e) / 2;
    update(node << 1, s, mid, l, r, x);
    update(node << 1 | 1, mid, e, l, r, x);
  }
  if (cnt[node] > 0) seg[node] = e - s;
  else seg[node] = seg[node << 1] + seg[node << 1 | 1];
}
int main() {
  fastio;
  int n, sx, sy, ex, ey;
  cin >> n;
  vector<tuple<int, int, int, bool>> a;
  for (int i = 0; i < n; ++i) {
    cin >> sx >> sy >> ex >> ey;
    a.pb({sx, sy, ey, 0});
    a.pb({ex, sy, ey, 1});
  }
  sort(all(a));
  int pre = get<0>(a[0]);
  ll ans = 0;
  for (auto [x, sy, ey, c] : a) {
    int dx = x - pre;
    ans += dx * seg[1];
    ll d = 1;
    if (c) d = -1;
    update(1, 0, _size, sy, ey, d);
    pre = x;
  }
  cout << ans << "\n";
}