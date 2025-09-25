#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;

  auto solve = [&](auto&& solve, int k, int p_cnt) -> void {
    if (k >= (int)s.size()) {
      if (p_cnt > 1) {
        std::cout << "NP\n";
        exit(0);
      } else {
        std::cout << "PPAP\n";
      }
      return;
    }
    if (s[k] == 'P') solve(solve, k + 1, p_cnt + 1);
    else if (s[k] == 'A') {
      if (p_cnt < 2 || k + 1 >= (int)s.size() || (p_cnt >= 2 && s[k + 1] != 'P')) {
        std::cout << "NP\n";
        exit(0);
      } else {
        solve(solve, k + 2, p_cnt - 1);
      }
    }
  };

  solve(solve, 0, 0);
}