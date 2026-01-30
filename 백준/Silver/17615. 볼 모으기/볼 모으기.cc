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
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    char x;
    std::cin >> x;
    if (x == 'B') {
      a[i] = 0;
    } else {
      a[i] = 1;
    }
  }

  int ans = 0x3f3f3f3f;
  for (int x = 0; x < 2; ++x) {
    bool start = false;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] != x) start = true;
      if (start && a[i] == x) cnt++;
    }
    ans = std::min(ans, cnt);

    start = false;
    cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (a[i] != x) start = true;
      if (start && a[i] == x) cnt++;
    }
    ans = std::min(ans, cnt);
  }

  std::cout << ans << "\n";
}