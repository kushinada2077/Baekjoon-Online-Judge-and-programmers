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

const int _size = 1 << 17;
vector<int> seg[_size << 1];

void construct() {
  for (int i = _size - 1; i != 0; --i) {
    auto& a1 = seg[i << 1];
    auto& a2 = seg[i << 1 | 1];
    int l = 0, r = 0;
    seg[i].resize(si(a1) + si(a2));
    for (int j = 0; j < si(a1) + si(a2); ++j) {
      if (l == si(a1)) seg[i][j] = a2[r++];
      else if (r == si(a2)) seg[i][j] = a1[l++];
      else if (a1[l] <= a2[r]) seg[i][j] = a1[l++];
      else seg[i][j] = a2[r++];
    }
  }
}
int my_greater(int node, int st, int en, int l, int r, int k) {
  if (en <= l || r <= st) return 0;
  if (l <= st && en <= r) return si(seg[node]) - (upper_bound(all(seg[node]), k) - seg[node].begin());
  int mid = (st + en) / 2;
  return my_greater(node << 1, st, mid, l, r, k) + my_greater(node << 1 | 1, mid, en, l, r, k);
}
int main() {
  fastio;
  int n, m, x, a, b, c, l = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    seg[_size + i].pb(x);
  }
  construct();
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    cout << (l = my_greater(ROOT, 0, _size, (a ^ l) - 1, b ^ l, c ^ l)) << "\n";
  }
}