#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n), c(1000001);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  int x, ans = 0;
  std::cin >> x;
  for (int i = 0; i < n; ++i) {
    if (x - a[i] > 0 && x - a[i] <= 1000000) ans += c[x - a[i]];
    c[a[i]]++;
  }

  std::cout << ans << "\n";
}