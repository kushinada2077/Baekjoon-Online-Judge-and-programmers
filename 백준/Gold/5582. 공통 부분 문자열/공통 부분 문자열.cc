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
  std::string s1, s2;
  std::cin >> s1 >> s2;
  int n = s1.size(), m = s2.size();
  std::vector<int> dp(m + 1), next(m + 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    next.assign(m + 1, 0);
    for (int j = 1; j <= m; ++j) {
      if (s1[i - 1] == s2[j - 1]) {
        next[j] = dp[j - 1] + 1;
        if (next[j] > ans) {
          ans = std::max(ans, next[j]);
        }
      }
    }
    std::swap(dp, next);
  }
  std::println("{}", ans);
}