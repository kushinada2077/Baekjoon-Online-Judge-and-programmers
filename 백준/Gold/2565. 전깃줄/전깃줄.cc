#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using TP = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n;
  std::cin >> n;
  std::vector<P> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i].first >> a[i].second;
  }
  std::ranges::sort(a);
  std::vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    b[i] = a[i].second;
  }

  std::vector<int> dp(n);
  for (int i = 0; i < n; ++i) {
    dp[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (b[j] < b[i]) {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
  }

  std::println("{}", n - *std::max_element(dp.begin(), dp.end()));
}