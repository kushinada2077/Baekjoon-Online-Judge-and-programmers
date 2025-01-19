#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string a, b;
  std::cin >> a >> b;
  if (a.size() > b.size()) {
    std::swap(a, b);
  }
  int n = a.size(), m = b.size();

  int max = 0;
  for (int i = -n; i < m; ++i) {
    int c = 0;
    bool ok = true;
    for (int j = 0; j < n; ++j) {
      if (i + j < 0 || i + j >= m) continue;
      else {
        if (a[j] + b[i + j] - 2 * '0' == 4) {
          ok = false;
          break;
        } else {
          c++;
        }
      }
    }

    if (ok == true) {
      max = std::max(max, c);
    }
  }

  std::cout << n + m - max << "\n";
}