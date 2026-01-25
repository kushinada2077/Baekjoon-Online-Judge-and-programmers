#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_LPATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n, m;
  std::cin >> n >> m;
  std::set<int> broken;
  for (int i = 0; i < m; ++i) {
    int x;
    std::cin >> x;
    broken.insert(x);
  }

  int ans = std::abs(100 - n);
  for (int x = 0; x <= 1000000; ++x) {
    bool ok = [&] {
      int copy = x;
      while (copy > 0) {
        if (broken.contains(copy % 10)) return false;
        copy /= 10;
      }

      return true;
    }();

    if (x == 0 && broken.contains(0)) continue;

    if (ok) {
      int cnt = 0;
      int copy = x;
      while (copy > 0) {
        cnt++;
        copy /= 10;
      }

      if (x == 0) cnt = 1;
      ans = std::min(ans, cnt + std::abs(x - n));
    }
  }

  std::cout << ans << "\n";
}