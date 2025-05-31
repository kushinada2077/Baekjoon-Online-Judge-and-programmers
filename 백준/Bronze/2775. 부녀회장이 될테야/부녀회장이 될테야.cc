#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  for (int i = 0; i < T; ++i) {
    int k, n;
    std::cin >> k >> n;
    std::vector a(15, std::vector<int>(15, 0));
    for (int i = 1; i < 15; ++i) {
      a[0][i] = i;
    }
    for (int i = 1; i < 15; ++i) {
      for (int j = 1; j < 15; ++j) {
        a[i][j] += a[i - 1][j] + a[i][j - 1];
      }
    }
    std::cout << a[k][n] << "\n";
  }
}