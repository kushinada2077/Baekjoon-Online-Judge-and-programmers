#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  double a, b;
  std::cin >> a >> b;
  std::vector a_p(19, std::vector<double>(19, 0)), b_p(19, std::vector<double>(19, 0));
  a_p[1][0] = (100 - a) / 100;
  a_p[1][1] = a / 100;
  b_p[1][0] = (100 - b) / 100;
  b_p[1][1] = b / 100;

  for (int i = 2; i <= 18; ++i) {
    a_p[i][0] = a_p[i - 1][0] * (100 - a) / 100;
    b_p[i][0] = b_p[i - 1][0] * (100 - b) / 100;
    for (int j = 1; j <= i; ++j) {
      a_p[i][j] = (a_p[i - 1][j - 1] * a / 100) + (a_p[i - 1][j] * (100 - a) / 100);
      b_p[i][j] = (b_p[i - 1][j - 1] * b / 100) + (b_p[i - 1][j] * (100 - b) / 100);
    }
  }
  auto is_prime = [&](int x) {
    int cnt = 0;
    for (int i = 1; i * i <= x; ++i) {
      if (x % i == 0) cnt += 2;
      if (i * i == x) cnt--;
    }

    return cnt == 2;
  };

  double sum_a = 0, sum_b = 0;
  for (int i = 0; i <= 18; ++i) {
    if (!is_prime(i)) {
      sum_a += a_p[18][i];
      sum_b += b_p[18][i];
    }
  }

  std::cout << std::fixed << std::setprecision(20);
  std::cout << (1 - (sum_a * sum_b)) << "\n";
}