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

const int _size = 1 << 19;
ll seg[_size << 1], cnt[_size << 1];
vector<int> uni;
void update(int node, int s, int e, int l, int r, int x) {
  if (e <= l || r <= s) return;
  if (l <= s && e <= r) cnt[node] += x;
  else {
    int mid = (s + e) / 2;
    update(node << 1, s, mid, l, r, x);
    update(node << 1 | 1, mid, e, l, r, x);
  }
  if (cnt[node] > 0) seg[node] = uni[e] - uni[s];
  else {
    if (s + 1 == e) seg[node] = 0;
    else seg[node] = seg[node << 1] + seg[node << 1 | 1];
  }
}
int main() {
  fastio;
  int n, sx, ex, sy, ey;
  cin >> n;
  vector<tuple<int, int, int, bool>> a;
  for (int i = 0; i < n; ++i) {
    cin >> sx >> ex >> sy >> ey;
    a.pb({sx, sy, ey, 0});
    a.pb({ex, sy, ey, 1});
    uni.pb(sy);
    uni.pb(ey);
  }
  sort(all(uni));
  uni.erase(unique(all(uni)), uni.end());
  sort(all(a));
  ll ans = 0;
  int pre = get<0>(a[0]);
  for (auto [x, sy, ey, c] : a) {
    int l = lower_bound(all(uni), sy) - uni.begin(), r = lower_bound(all(uni), ey) - uni.begin();
    ans += 1ll * seg[1] * (x - pre);
    int d = 1;
    if (c) d *= -1;
    update(1, 0, _size, l, r, d);
    pre = x;
  }
  cout << ans << "\n";
}