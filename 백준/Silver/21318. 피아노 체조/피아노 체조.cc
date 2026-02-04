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
  int n;
  std::cin >> n;
  std::vector<int> a(n), pref(n + 1);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1];
    pref[i] += a[i - 1] > a[i];
  }

  int q;
  std::cin >> q;

  for (int i = 0; i < q; ++i) {
    int x, y;
    std::cin >> x >> y;
    x--;
    y--;

    std::cout << pref[y] - pref[x] << "\n";
  }
}