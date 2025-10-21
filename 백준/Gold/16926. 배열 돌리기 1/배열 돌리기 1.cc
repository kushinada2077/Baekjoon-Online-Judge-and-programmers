#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, r;
  std::cin >> n >> m >> r;
  std::vector arr(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> arr[i][j];
    }
  }

  int p = std::min(n, m) / 2;
  std::vector rotation(p, std::vector<int>());
  int sy = 0, sx = 0;
  for (int i = 0; i < p; ++i, ++sy, ++sx) {
    for (int y = sy; y < n - sy - 1; ++y) rotation[i].push_back(arr[y][i]);
    for (int x = sx; x < m - sx - 1; ++x) rotation[i].push_back(arr[n - sy - 1][x]);
    for (int y = n - sy - 1; y > i; --y) rotation[i].push_back(arr[y][m - sx - 1]);
    for (int x = m - sx - 1; x > i; --x) rotation[i].push_back(arr[i][x]);
  }

  auto next = [&](int& x, int r) {
    int tmp = x;
    x = (x + 1) % r;
    return tmp;
  };

  std::vector ans(n, std::vector<int>(m, 0));
  for (int i = 0; i < p; ++i) {
    int k = (int)rotation[i].size();
    int tmp = r % k;
    int j = (k - tmp) % k;

    for (int y = i; y < n - i - 1; ++y) ans[y][i] = rotation[i][next(j, k)];
    for (int x = i; x < m - i - 1; ++x) ans[n - i - 1][x] = rotation[i][next(j, k)];
    for (int y = n - i - 1; y > i; --y) ans[y][m - i - 1] = rotation[i][next(j, k)];
    for (int x = m - i - 1; x > i; --x) ans[i][x] = rotation[i][next(j, k)];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cout << ans[i][j] << " \n"[j == m - 1];
    }
  }
}