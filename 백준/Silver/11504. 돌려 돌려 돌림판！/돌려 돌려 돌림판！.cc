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
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  int x = 0, y = 0;
  int digit = 1;
  for (int i = 0; i < m - 1; ++i) {
    digit *= 10;
  }
  for (int i = 0, ten = digit; i < m; ++i, ten /= 10) {
    int k;
    std::cin >> k;
    x += k * ten;
  }
  for (int i = 0, ten = digit; i < m; ++i, ten /= 10) {
    int k;
    std::cin >> k;
    y += k * ten;
  }

  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  int cnt = 0;
  digit = 1;
  for (int i = 0; i < m - 1; ++i) digit *= 10;
  for (int i = 0; i < n; ++i) {
    int res = 0;
    for (int j = 0, ten = digit; j < m; ++j, ten /= 10) {
      res += ten * a[(i + j) % n];
    }

    if (x <= res && res <= y) cnt++;
  }

  std::cout << cnt << "\n";
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