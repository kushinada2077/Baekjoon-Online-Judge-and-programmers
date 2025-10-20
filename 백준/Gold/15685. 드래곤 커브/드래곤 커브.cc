#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  int min_y = 100001, min_x = 100001, max_x = -100001, max_y = -100001;
  std::map<int, std::map<int, int>> chk;

  std::vector curve_dir(11, std::vector(4, std::vector<int>()));
  curve_dir[0][0] = {0};
  curve_dir[0][1] = {1};
  curve_dir[0][2] = {2};
  curve_dir[0][3] = {3};
  for (int g = 1; g <= 10; ++g) {
    for (int dir = 0; dir < 4; ++dir) {
      curve_dir[g][dir] = curve_dir[g - 1][dir];
      for (auto it = curve_dir[g - 1][dir].rbegin(); it != curve_dir[g - 1][dir].rend(); ++it) {
        curve_dir[g][dir].push_back(((*it) + 1) % 4);
      }
    }
  }

  std::vector<int> dx = {1, 0, -1, 0}, dy = {0, -1, 0, 1};

  for (int i = 0; i < n; ++i) {
    int x, y, d, g;
    std::cin >> x >> y >> d >> g;
    min_y = std::min(min_y, y);
    max_y = std::max(max_y, y);
    min_x = std::min(min_x, x);
    max_x = std::max(max_x, x);
    chk[x][y] = 1;

    for (int dir : curve_dir[g][d]) {
      x += dx[dir];
      y += dy[dir];
      chk[x][y] = 1;
      min_y = std::min(min_y, y);
      max_y = std::max(max_y, y);
      min_x = std::min(min_x, x);
      max_x = std::max(max_x, x);
    }
  }

  int ans = 0;

  for (int x = min_x; x <= max_x; ++x) {
    for (int y = min_y; y <= max_y; ++y) {
      if (chk[x][y] == 1 && chk[x][y + 1] == 1 && chk[x + 1][y] == 1 && chk[x + 1][y + 1] == 1) {
        ans++;
      }
    }
  }

  std::cout << ans << "\n";
}
