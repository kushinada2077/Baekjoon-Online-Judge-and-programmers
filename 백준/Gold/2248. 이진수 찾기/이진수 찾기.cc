#include <bits/stdc++.h>
using i64 = long long;

i64 dp[32][32];
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 N, L, I;
  std::cin >> N >> L >> I;
  dp[0][0] = 1;
  for (int i = 1; i <= N; ++i) {
    dp[i][0] = dp[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }
  }

  std::string ans = "";
  i64 l = L;
  for (int i = N; i > 0; --i) {
    i64 tot = 0;
    for (int j = 0; j <= l; ++j) {
      tot += dp[i - 1][j];
    }
    if (I > tot) {
      I -= tot;
      ans += '1';
      l--;
    } else {
      ans += '0';
    }
  }

  std::cout << ans << "\n";
}