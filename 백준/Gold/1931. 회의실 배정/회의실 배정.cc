#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> ts(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> ts[i].second >> ts[i].first;
  }
  sort(ts.begin(), ts.end());
  int ans = 0, e = -1;
  for (int i = 0; i < n; ++i) {
    if (e <= ts[i].second) {
      ans++;
      e = ts[i].first;
    }
  }

  std::cout << ans << "\n";
}