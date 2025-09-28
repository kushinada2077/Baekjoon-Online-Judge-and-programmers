#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, r;
  std::cin >> n >> m >> r;
  std::vector a(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) std::cin >> a[i][j];
  }

  auto rotate = [&](int offset, int cir, int sy, int ey, int sx, int ex) {
    int idx = cir - offset - 1;

    std::vector<int> b;
    auto next = [&](int idx) { return (idx + 1) % cir; };

    for (int i = sy; i < ey; ++i) b.push_back(a[i][sx]);
    for (int j = sx; j < ex; ++j) b.push_back(a[ey][j]);
    for (int i = ey; i > sy; --i) b.push_back(a[i][ex]);
    for (int j = ex; j > sx; --j) b.push_back(a[sy][j]);

    for (int i = sy; i < ey; ++i) a[i][sx] = b[idx = next(idx)];
    for (int j = sx; j < ex; ++j) a[ey][j] = b[idx = next(idx)];
    for (int i = ey; i > sy; --i) a[i][ex] = b[idx = next(idx)];
    for (int j = ex; j > sx; --j) a[sy][j] = b[idx = next(idx)];
  };

  auto cir = [&](int n, int m) { return 2 * n + 2 * m - 4; };

  int k = std::min(n, m);

  for (int i = 0; i < k / 2; ++i) {
    int cir_len = cir(n - 2 * i, m - 2 * i);
    int offset = r % cir_len;
    rotate(offset, cir_len, i, n - i - 1, i, m - i - 1);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cout << a[i][j] << " \n"[j == m - 1];
    }
  }
}