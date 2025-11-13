#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using P_i64 = std::pair<i64, i64>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, ans = 0;
  std::cin >> n;
  std::vector<P> q;
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    q.push_back({a, b});
  }

  std::ranges::sort(q, [&](P p1, P p2) {
    auto [a1, b1] = p1;
    auto [a2, b2] = p2;
    if (a1 == a2) return b1 - a1 > b2 - a2;
    return a1 < a2;
  });

  const int h = 1001, w = 367;

  std::vector board(h, std::vector<int>(w, 0));

  auto ok = [&](int y, int a, int b) {
    for (int x = a; x <= b; ++x) {
      if (board[y][x] == 1) return false;
    }

    return true;
  };

  auto fill = [&](int a, int b) {
    for (int i = 0;; ++i) {
      if (ok(i, a, b)) {
        for (int j = a; j <= b; ++j) board[i][j] = 1;
        return;
      }
    }
  };

  for (auto [a, b] : q) fill(a, b);
  std::vector<int> max_y(w, -1);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (board[i][j] == 1) max_y[j] = std::max(max_y[j], i);
    }
  }

  int pre_j = 0, pre_i = -1;
  for (int j = 1; j < w; ++j) {
    if (max_y[j] == -1) {
      if (pre_i != -1) ans += (j - pre_j - 1) * (pre_i + 1);
      pre_j = j;
      pre_i = -1;
    }
    pre_i = std::max(pre_i, max_y[j]);
  }

  std::cout << ans << "\n";
}