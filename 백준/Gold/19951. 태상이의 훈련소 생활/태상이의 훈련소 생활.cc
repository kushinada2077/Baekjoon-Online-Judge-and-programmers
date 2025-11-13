#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using P_i64 = std::pair<i64, i64>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), d(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < m; ++i) {
    int a, b, k;
    std::cin >> a >> b >> k;
    a--;
    b--;
    d[a] += k;
    if (b + 1 < n) d[b + 1] -= k;
  }

  for (int i = 1; i < n; ++i) d[i] += d[i - 1];
  for (int i = 0; i < n; ++i) std::cout << a[i] + d[i] << " \n"[i == n - 1];
}