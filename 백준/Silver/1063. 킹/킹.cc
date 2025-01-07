#include <bits/stdc++.h>
using i64 = long long;

std::string d[9] = {"LB", "B", "RB", "L", " ", "R", "LT", "T", "RT"};
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string k, s;
  int n;
  std::cin >> k >> s >> n;
  int ky = k[1] - '0', kx = k[0] - 'A' + 1;
  int sy = s[1] - '0', sx = s[0] - 'A' + 1;

  for (int i = 0; i < n; ++i) {
    std::string op;
    std::cin >> op;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (i == 1 && j == 1) continue;
        if (d[3 * i + j] == op) {
          int ny = ky + i - 1, nx = kx + j - 1;
          if (ny < 1 || ny > 8 || nx < 1 || nx > 8) continue;
          if (ny == sy && nx == sx) {
            int nsy = sy + i - 1, nsx = sx + j - 1;
            if (nsy < 1 || nsy > 8 || nsx < 1 || nsx > 8) continue;
            sy = nsy;
            sx = nsx;
          }
          ky = ny;
          kx = nx;
        }
      }
    }
  }

  std::cout << char(kx + 'A' - 1) << ky << "\n";
  std::cout << char(sx + 'A' - 1) << sy << "\n";
}