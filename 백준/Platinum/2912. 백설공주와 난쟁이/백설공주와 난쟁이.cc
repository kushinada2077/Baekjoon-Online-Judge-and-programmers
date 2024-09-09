#include <algorithm>
#include <iostream>
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
vector<int> seg[_size << 1], c_list[10005];

void construct() {
  for (int i = _size - 1; i != 0; --i) {
    auto& c = seg[i];
    auto& a1 = seg[i << 1];
    auto& a2 = seg[i << 1 | 1];
    c.resize(si(a1) + si(a2));
    for (int j = 0, l = 0, r = 0; j < si(c); ++j) {
      if (r == si(a2) || (l < si(a1) && a1[l] <= a2[r])) c[j] = a1[l++];
      else c[j] = a2[r++];
    }
  }
}
void find(int node, int st, int en, int l, int r, vector<int>& group) {
  if (en <= l || r <= st) return;
  if (l <= st && en <= r) {
    auto& arr = seg[node];
    int si = si(arr);
    if (si == 1) group.pb(seg[node].front());
    else if (si > 1 && arr[si / 2] == arr[si / 2 - 1]) group.pb(arr[si / 2]);
    return;
  }
  int mid = (st + en) / 2;
  find(node << 1, st, mid, l, r, group);
  find(node << 1 | 1, mid, en, l, r, group);
}
int main() {
  fastio;
  int n, m, c, x, a, b, l;
  cin >> n >> c;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    c_list[x].pb(i);
    seg[_size + i].pb(x);
  }
  construct();
  for (int i = 1; i <= c; ++i) sort(all(c_list[i]));
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    l = b - a + 1;
    vector<int> group;
    find(ROOT, 0, _size, a - 1, b, group);
    bool failed = true;
    for (auto& c : group) {
      if (l / 2 < upper_bound(all(c_list[c]), b - 1) - lower_bound(all(c_list[c]), a - 1)) {
        cout << "yes " << c << "\n";
        failed = false;
        break;
      }
    }
    if (failed) cout << "no\n";
  }
}