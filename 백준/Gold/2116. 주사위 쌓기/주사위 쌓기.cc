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
  std::vector ds(n, std::vector<int>(6));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 6; ++j) {
      std::cin >> ds[i][j];
    }
  }

  auto pair = [&](int x) {
    if (x == 0) return 5;
    if (x == 1) return 3;
    if (x == 2) return 4;
    if (x == 3) return 1;
    if (x == 4) return 2;
    return 0;
  };

  // dp[i][j] = i번쨰 주사위까지 사용했을 때 윗면이 j번째 면일때 옆면의 최댓값
  std::vector dp(n, std::vector<int>(6));
  for (int j = 0; j < 6; ++j) {
    int max = 0;
    for (int k = 0; k < 6; ++k) {
      if (k != j && k != pair(j)) {
        max = std::max(max, ds[0][k]);
      }
    }
    dp[0][j] = max;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 6; ++j) {
      int idx = 0;
      for (int k = 0; k < 6; ++k) {
        if (ds[i][pair(j)] == ds[i - 1][k]) {
          idx = k;
          break;
        }
      }
      int max = 0;
      for (int k = 0; k < 6; ++k) {
        if (k != pair(j) && k != j) {
          max = std::max(max, ds[i][k]);
        }
      }

      dp[i][j] = dp[i - 1][idx] + max;
    }
  }

  int ans = 0;
  for (int j = 0; j < 6; ++j) {
    ans = std::max(ans, dp[n - 1][j]);
  }

  std::println("{}", ans);
}