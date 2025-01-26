#include <bits/stdc++.h>
using i64 = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    int x;
    std::cin >> x;
    ans += a.end() - upper_bound(a.begin(), a.end(), x);
  }

  std::cout << ans << "\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
}