#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int p = a.back(), ans = 0;
  for (int i = n - 2; i >= 0; --i) {
    if (a[i] >= p) {
      ans += abs(p - 1 - a[i]);
      a[i] = p - 1;
    }
    p = a[i];
  }

  std::cout << ans << "\n";
}