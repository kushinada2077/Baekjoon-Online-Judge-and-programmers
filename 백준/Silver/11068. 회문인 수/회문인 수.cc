#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

void solve() {
  int x;
  std::cin >> x;

  int ans = 0;
  for (int b = 2; b <= 64; ++b) {
    std::vector<int> a;
    int y = x;
    while (y > 0) {
      a.push_back(y % b);
      y /= b;
    }

    int n = (int)a.size();

    int ok = [&] {
      for (int i = 0; i < n / 2; ++i) {
        if (a[i] != a[n - i - 1]) return 0;
      }

      return 1;
    }();

    if (ok == 1) {
      ans = 1;
      break;
    }
  }

  std::cout << ans << "\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
}