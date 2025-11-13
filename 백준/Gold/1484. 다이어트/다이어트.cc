#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using P_i64 = std::pair<i64, i64>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int g;
  std::cin >> g;

  std::vector<i64> b;
  i64 x = 1;
  while (x * x - (x - 1) * (x - 1) <= g) {
    b.push_back(x);
    x++;
  }

  int n = (int)b.size();
  bool ok = false;
  int j = 0;
  for (int i = 0; i < n; ++i) {
    for (; b[i] * b[i] - b[j] * b[j] > g; ++j);
    if (b[i] * b[i] - b[j] * b[j] == g) {
      std::cout << b[i] << "\n";
      ok = true;
    }
  }

  if (ok == false) std::cout << "-1\n";
}