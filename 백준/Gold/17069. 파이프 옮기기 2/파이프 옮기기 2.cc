#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n;
  std::cin >> n;
  std::vector board(n, std::vector<int>(n));
  std::vector dp(n, std::vector(n, std::vector<i64>(3, -1)));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> board[i][j];
    }
  }

  auto chk = [&](int y, int x, int state) -> bool {
    if (y < 0 || y >= n || x < 0 || x >= n) return false;
    if (board[y][x] == 1) return false;
    if (state == 0) return x + 1 < n && board[y][x + 1] == 0;
    else if (state == 1) return y + 1 < n && board[y + 1][x] == 0;
    else return y + 1 < n && x + 1 < n && board[y + 1][x] == 0 && board[y][x + 1] == 0 && board[y + 1][x + 1] == 0;
  };

  auto dfs = [&](auto&& dfs, int y, int x, int state) -> i64 {
    if (!chk(y, x, state)) return 0LL;
    if (state == 0 && y == n - 1 && x + 1 == n - 1) return 1LL;
    if (state == 1 && y + 1 == n - 1 && x == n - 1) return 1LL;
    if (state == 2 && y + 1 == n - 1 && x + 1 == n - 1) return 1LL;
    if (dp[y][x][state] != -1) return dp[y][x][state];
    i64 res = 0LL;

    if (state == 0) {
      res += dfs(dfs, y, x + 1, 0);
      res += dfs(dfs, y, x + 1, 2);
    }
    if (state == 1) {
      res += dfs(dfs, y + 1, x, 1);
      res += dfs(dfs, y + 1, x, 2);
    }
    if (state == 2) {
      res += dfs(dfs, y + 1, x + 1, 0);
      res += dfs(dfs, y + 1, x + 1, 1);
      res += dfs(dfs, y + 1, x + 1, 2);
    }

    if (dp[y][x][state] == -1) dp[y][x][state] = res;
    else dp[y][x][state] += res;
    return dp[y][x][state];
  };

  std::cout << dfs(dfs, 0, 0, 0) << "\n";
}