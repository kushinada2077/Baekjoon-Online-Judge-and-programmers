#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

int main() {
  fastio;
  int n, k, ans = 0x3f3f3f3f;
  cin >> n >> k;
  vector<int> p(n, 1);
  fill(p.begin(), p.begin() + k, 0);
  vector<pair<int, int>> a(n);
  for (auto& [i, j] : a) cin >> i >> j;

  do {
    vector<pair<int, int>> s;
    int mx = -1;
    for (int i = 0; i < n; ++i)
      if (p[i] == 0) s.pb(a[i]);
    for (int i = 0; i < n; ++i) {
      if (p[i] == 0) continue;
      int dis = 0x3f3f3f3f;
      for (int j = 0; j < k; ++j) dis = min(dis, abs(a[i].X - s[j].X) + abs(a[i].Y - s[j].Y));
      mx = max(mx, dis);
    }
    ans = min(ans, mx);
  } while (next_permutation(all(p)));
  cout << ans << "\n";
}