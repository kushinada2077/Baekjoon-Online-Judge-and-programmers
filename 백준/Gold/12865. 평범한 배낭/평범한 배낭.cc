#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> dp(k + 1, -1);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    int w, v;
    std::cin >> w >> v;
    for (int j = k; j >= 1; --j) {
      if (j - w >= 0 && dp[j - w] != -1) dp[j] = std::max(dp[j], dp[j - w] + v);
    }
  }

  std::cout << *max_element(dp.begin(), dp.end()) << "\n";
}