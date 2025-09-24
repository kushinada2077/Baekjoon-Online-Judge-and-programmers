#include <bits/stdc++.h>
using i64 = long long;

constexpr int IMPOSSIBLE = 0x3f3f3f3f;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
  }

  if (n == 1) {
    std::cout << "A\n";
  } else if (std::ranges::all_of(p, [&](int x) { return x == p.front(); })) std::cout << p.front() << "\n";
  else if (p[1] - p[0] == 0) {
    std::cout << "B\n";
  } else if (n < 3) {
    std::cout << "A\n";
  } else {
    int a = (p[2] - p[1]) / (p[1] - p[0]);
    int b = p[1] - a * p[0];

    for (int i = 0; i < n - 1; ++i) {
      if (a * p[i] + b != p[i + 1]) {
        std::cout << "B\n";
        return 0;
      }
    }

    std::cout << a * p.back() + b << "\n";
  }
}