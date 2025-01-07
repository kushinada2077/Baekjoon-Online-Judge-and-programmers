#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::vector<int> a(5);
  for (int i = 0; i < 5; ++i) std::cin >> a[i];
  int ans = 0x3f3f3f3f;
  for (int i = 0; i < 5; ++i) {
    for (int j = i + 1; j < 5; ++j) {
      for (int k = j + 1; k < 5; ++k) {
        int b = a[i] * a[j] / std::gcd(a[i], a[j]);
        b = b * a[k] / std::gcd(b, a[k]);
        ans = std::min(ans, b);
      }
    }
  }

  std::cout << ans << "\n";
}