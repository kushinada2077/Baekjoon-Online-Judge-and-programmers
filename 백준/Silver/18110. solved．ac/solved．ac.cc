#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n;
  std::cin >> n;

  if (n == 0) {
    std::cout << 0 << "\n";
    return 0;
  }
  std::vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::ranges::sort(a);

  int offset = round(0.15f * n);

  for (int i = offset; i < n - offset; ++i) {
    sum += a[i];
  }

  int x = n - (2 * offset);
  std::cout << round(1.0f * sum / x) << "\n";
}