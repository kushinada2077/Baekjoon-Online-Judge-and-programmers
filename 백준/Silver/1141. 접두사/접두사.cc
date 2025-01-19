#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  sort(a.begin(), a.end());
  auto ispre = [&](const std::string& a, const std::string& b) {
    int n = a.size(), m = b.size();
    if (n > m) return false;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) return false;
    }
    return true;
  };

  int ans = 1;
  for (int i = 0; i < n - 1; ++i) {
    ans += !ispre(a[i], a[i + 1]);
  }

  std::cout << ans << "\n";
}