#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;
using F = std::tuple<int, int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n;
  std::cin >> n;
  std::vector ans = {"CY", "SK"};
  std::vector<bool> dp(n + 1);

  for (int i = 2; i <= n; ++i) {
    for (int k : {1, 3, 4}) {
      if (i - k > 0 && dp[i - k] == false) dp[i] = true;
    }
  }

  std::cout << ans[dp[n]] << "\n";
}