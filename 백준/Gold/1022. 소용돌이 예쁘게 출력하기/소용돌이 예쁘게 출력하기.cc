#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int max_digit = 0;
  std::vector<i64> dp(5001, -1);

  auto f = [&](auto&& f, int x) -> i64 {
    if (x == 0) return 1LL;
    if (x == 1) return 3LL;
    if (dp[x] != -1) return dp[x];
    return dp[x] = 2 * f(f, x - 1) - f(f, x - 2) + 8;
  };

  auto digit = [&](int x) {
    int ret = 0;
    while (x > 0) {
      x /= 10;
      ret++;
    }

    return ret;
  };

  auto padding = [&](int x, int digit) {
    std::string ret = "";
    while (x > 0) {
      ret += std::to_string(x % 10);
      x /= 10;
    }

    while ((int)ret.size() < digit) {
      ret += ' ';
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
  };

  auto solve = [&](int y, int x) -> i64 {
    int layer = std::max(std::abs(y), std::abs(x));
    i64 ret = f(f, layer);

    if (x == layer && y != layer) ret -= y + layer;
    else if (y == -layer) ret += layer - x;
    else if (x == -layer) ret += 2 * layer + y + layer;
    else if (y == layer) ret += 4 * layer + x + layer;

    max_digit = std::max(max_digit, digit(ret));
    return ret;
  };

  int r1, c1, r2, c2;
  std::cin >> r1 >> c1 >> r2 >> c2;
  std::vector ans(r2 - r1 + 1, std::vector<i64>(c2 - c1 + 1));
  for (int i = r1; i <= r2; ++i) {
    for (int j = c1; j <= c2; ++j) {
      ans[i - r1][j - c1] = solve(i, j);
    }
  }

  for (int i = 0; i < r2 - r1 + 1; ++i) {
    for (int j = 0; j < c2 - c1 + 1; ++j) {
      std::cout << padding(ans[i][j], max_digit) << " \n"[j == c2 - c1];
    }
  }
}
