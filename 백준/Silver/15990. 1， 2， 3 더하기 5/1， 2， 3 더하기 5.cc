#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

const int M = 1e9 + 9;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int t;
  std::cin >> t;

  std::vector dp(100001, std::vector<int>(3));

  dp[1][0] = 1;
  dp[2][1] = 1;
  dp[3][0] = 1;
  dp[3][1] = 1;
  dp[3][2] = 1;

  for (int i = 4; i <= 100000; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (j == 0) {
        dp[i][j] = (1LL * dp[i - 1][1] + dp[i - 1][2]) % M;
      } else if (j == 1) {
        dp[i][j] = (1LL * dp[i - 2][0] + dp[i - 2][2]) % M;
      } else {
        dp[i][j] = (1LL * dp[i - 3][0] + dp[i - 3][1]) % M;
      }
    }
  }
  while (t--) {
    int n;
    std::cin >> n;
    std::cout << (1LL * dp[n][0] + dp[n][1] + dp[n][2]) % M << "\n";
  }
}