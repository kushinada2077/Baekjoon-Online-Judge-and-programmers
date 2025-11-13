#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using P_i64 = std::pair<i64, i64>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int g;
  std::cin >> g;

  std::vector<i64> a;
  std::set<i64> b;
  std::map<i64, i64> c;

  i64 x = 1;

  while ((x + 1) * (x + 1) - x * x <= g) {
    a.push_back(x);
    b.insert(x * x);
    c[x * x] = x;
    x++;
  }

  a.push_back(x);
  b.insert(x * x);
  c[x * x] = x;

  bool ok = false;
  for (auto x : a) {
    if (b.contains(x * x - g)) {
      std::cout << c[x * x] << "\n";
      ok = true;
    }
  }

  if (ok == false) std::cout << -1 << "\n";
}