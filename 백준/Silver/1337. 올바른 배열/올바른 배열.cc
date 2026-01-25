#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;
const int INF = 1e9;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::set<int> b;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    b.insert(a[i]);
  }
  int ans = 0x3f3f3f;

  for (auto x : a) {
    int cnt = 0;
    for (int d = 1; d <= 4; ++d) {
      cnt += !b.contains(x + d);
    }

    ans = std::min(ans, cnt);
  }

  std::cout << ans << "\n";
}