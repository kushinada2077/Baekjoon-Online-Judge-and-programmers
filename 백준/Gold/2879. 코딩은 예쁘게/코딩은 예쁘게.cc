#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> diff(n), b(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> diff[i];
  }

  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    diff[i] = x - diff[i];
  }

  int ans = 0, add = 0, remove = 0;
  for (int i = 0; i < n; ++i) {
    if (diff[i] > 0) {
      if (add < diff[i]) ans += diff[i] - add;
      add = diff[i];
      remove = 0;
    } else {
      if (remove < -diff[i]) ans += -diff[i] - remove;
      remove = -diff[i];
      add = 0;
    }
  }

  std::cout << ans << "\n";
}