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
  int k;
  std::cin >> k;
  int n = (1 << k) - 1;
  std::vector<int> a(n);
  std::vector ans(k, std::vector<int>());
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  int cnt = 0;

  auto dfs = [&](auto&& dfs, int x, int depth) -> void {
    if (2 * x <= n) dfs(dfs, 2 * x, depth + 1);
    ans[depth].push_back(a[cnt++]);
    if (2 * x + 1 <= n) dfs(dfs, 2 * x + 1, depth + 1);
    return;
  };

  dfs(dfs, 1, 0);
  for (int i = 0; i < k; ++i) {
    for (auto x : ans[i]) std::cout << x << " ";
    std::cout << "\n";
  }
}