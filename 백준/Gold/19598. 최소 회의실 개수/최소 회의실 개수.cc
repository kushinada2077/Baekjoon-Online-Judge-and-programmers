#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using P_i64 = std::pair<i64, i64>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, cur = 0, ans = 0;
  std::cin >> n;
  std::vector<P> q;

  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    q.push_back({a, 1});
    q.push_back({b, 0});
  }

  std::ranges::sort(q);
  for (auto [x, type] : q) {
    if (type == 0) cur--;
    if (type == 1) cur++;
    ans = std::max(ans, cur);
  }

  std::cout << ans << "\n";
}