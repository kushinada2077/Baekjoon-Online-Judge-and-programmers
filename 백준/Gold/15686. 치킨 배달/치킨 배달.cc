#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

template <class T, class U>
inline bool chmin(T& a, const U& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

inline int distance(int x1, int y1, int x2, int y2) {
  return std::abs(x1 - x2) + std::abs(y1 - y2);
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector board(n, std::vector<int>(n));
  std::vector<P> house, chick;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> board[i][j];
      if (board[i][j] == 1) {
        house.push_back({i, j});

      } else if (board[i][j] == 2) {
        chick.push_back({i, j});
      }
    }
  }

  std::vector<int> bit((int)chick.size(), 1);
  for (int i = 0; i < m; ++i) {
    bit[i] = 0;
  }

  int ans = 0x3f3f3f3f;
  do {
    int tot = 0;
    for (auto [sx, sy] : house) {
      int min = 0x3f3f3f3f;
      for (int i = 0; i < (int)bit.size(); ++i) {
        if (bit[i] == 0) {
          int d = distance(sx, sy, chick[i].first, chick[i].second);
          chmin(min, d);
        }
      }

      tot += min;
    }
    chmin(ans, tot);
  } while (std::next_permutation(bit.begin(), bit.end()));

  std::cout << ans << "\n";
}