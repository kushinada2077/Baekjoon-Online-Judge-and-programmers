#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::vector J(n + 1, std::vector<int>(m + 1, 0));
  auto O = J, I = J;

  for (int i = 0; i < n; ++i) {
    int cnt_j = 0, cnt_o = 0, cnt_i = 0;
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 'J') cnt_j++;
      if (a[i][j] == 'O') cnt_o++;
      if (a[i][j] == 'I') cnt_i++;
      J[i + 1][j + 1] = J[i][j + 1] + cnt_j;
      O[i + 1][j + 1] = O[i][j + 1] + cnt_o;
      I[i + 1][j + 1] = I[i][j + 1] + cnt_i;
    }
  }

  auto prefix_sum = [](std::vector<std::vector<int>>& a, int sy, int sx, int ey, int ex) {
    int ret = a[ey + 1][ex + 1];
    ret -= a[ey + 1][sx] + a[sy][ex + 1];
    ret += a[sy][sx];
    return ret;
  };

  for (int i = 0; i < k; ++i) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    d--;
    std::cout << prefix_sum(J, a, b, c, d) << " " << prefix_sum(O, a, b, c, d) << " " << prefix_sum(I, a, b, c, d) << "\n";
  }
}