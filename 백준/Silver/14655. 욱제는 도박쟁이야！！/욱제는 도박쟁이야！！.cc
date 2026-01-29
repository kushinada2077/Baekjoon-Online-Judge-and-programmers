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
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ans += std::abs(x);
  }

  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
  }

  std::cout << 2 * ans << "\n";
}