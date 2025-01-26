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
  if (n == 1) {
    std::cout << "권병장님, 중대장님이 찾으십니다\n";
    return 0;
  }
  std::vector<int> b(n);
  for (int i = 0; i < n - 1; ++i) {
    std::cin >> b[i];
  }
  int max = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (max >= a[i]) {
      max = std::max(max, a[i] + b[i]);
    }
  }

  if (max >= a.back()) {
    std::cout << "권병장님, 중대장님이 찾으십니다\n";
  } else {
    std::cout << "엄마 나 전역 늦어질 것 같아\n";
  }
}