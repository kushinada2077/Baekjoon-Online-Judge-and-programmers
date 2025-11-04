#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<i64> plus, amari;
  i64 one = 0;
  for (int i = 0; i < n; ++i) {
    i64 x;
    std::cin >> x;
    if (x == 1) one++;
    else if (x > 1) plus.push_back(x);
    else amari.push_back(x);
  }

  std::ranges::sort(plus);
  std::ranges::sort(amari);

  i64 ans = 0;
  int m = (int)plus.size();
  for (int i = m - 1; i - 1 >= 0; i -= 2) {
    ans += plus[i] * plus[i - 1];
  }
  if (m % 2 == 1) ans += plus.front();

  m = (int)amari.size();
  for (int i = 0; i + 1 < m; i += 2) {
    ans += amari[i] * amari[i + 1];
  }
  if (m % 2 == 1) ans += amari.back();
  ans += one;
  std::cout << ans << "\n";
}