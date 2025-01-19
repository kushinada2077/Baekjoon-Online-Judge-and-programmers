#include <bits/stdc++.h>
using i64 = long long;

std::vector<std::vector<int>> divide(int n, std::vector<std::vector<int>>& a) {
  std::vector ret(n / 2, std::vector<int>(n / 2));
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < n; j += 2) {
      std::vector<int> t;
      for (int dir = 0; dir < 4; ++dir) {
        int ni = i + "1122"[dir] - '1', nj = j + "1212"[dir] - '1';
        t.push_back(a[ni][nj]);
      }
      sort(t.begin(), t.end());
      ret[i / 2][j / 2] = t[2];
    }
  }
  return ret;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector a(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> a[i][j];
    }
  }

  while (n != 1) {
    a = divide(n, a);
    n /= 2;
  }

  std::cout << a[0][0] << "\n";
}