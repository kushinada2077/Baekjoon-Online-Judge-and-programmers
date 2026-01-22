#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;
using F = std::tuple<int, int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  std::set<std::string> d;
  int idx = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (a[i] == "?") idx = i;
    d.insert(a[i]);
  }

  int m;
  std::cin >> m;
  std::vector<std::string> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }

  if (n == 1) {
    std::cout << b[0] << "\n";
  } else {
    if (idx == 0) {
      for (int i = 0; i < m; ++i) {
        if (d.contains(b[i])) continue;
        if (a[idx + 1].front() == b[i].back()) {
          std::cout << b[i] << "\n";
        }
      }
    } else if (idx == n - 1) {
      for (int i = 0; i < m; ++i) {
        if (d.contains(b[i])) continue;
        if (a[idx - 1].back() == b[i].front()) {
          std::cout << b[i] << "\n";
        }
      }
    } else {
      for (int i = 0; i < m; ++i) {
        if (d.contains(b[i])) continue;
        if (a[idx - 1].back() == b[i].front() && a[idx + 1].front() == b[i].back()) {
          std::cout << b[i] << "\n";
        }
      }
    }
  }
}