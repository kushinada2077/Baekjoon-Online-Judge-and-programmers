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
  const int MAX = 1e9;
  int n;
  std::cin >> n;
  std::vector<i64> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  a[0] = b[0];
  if (a[0] < 1 || a[0] > MAX) {
    std::cout << "-1\n";
    return 0;
  }

  i64 sum = a[0];
  for (int i = 1; i < n; ++i) {
    if (sum <= b[i] * i) a[i] = b[i];
    else {
      a[i] = b[i] + 1;
      if (sum <= a[i] * i) {
        std::cout << "-1\n";
        return 0;
      }
    }
    if (a[i] < 1 || a[i] > MAX) {
      std::cout << "-1\n";
      return 0;
    }
    sum += a[i];
  }

  for (int i = 0; i < n; ++i) {
    std::cout << a[i] << " \n"[i == n - 1];
  }
}