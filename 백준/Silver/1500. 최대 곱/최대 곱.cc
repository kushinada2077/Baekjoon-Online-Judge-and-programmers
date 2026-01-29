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
  int s, k;
  std::cin >> s >> k;
  int x = s / k;
  int y = s % k;

  i64 ans = 1;

  for (int i = 0; i < k; ++i) {
    if (i < y) ans = (ans * (x + 1));
    else ans = (ans * x);
  }

  std::cout << ans << "\n";
}