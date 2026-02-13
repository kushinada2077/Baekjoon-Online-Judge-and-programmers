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
  int n, s, r;
  std::cin >> n >> s >> r;
  std::vector<int> ss(n), rr(n);
  for (int i = 0; i < s; ++i) {
    int x;
    std::cin >> x;
    ss[x - 1] = 1;
  }

  for (int i = 0; i < r; ++i) {
    int x;
    std::cin >> x;
    rr[x - 1] = 1;
    if (ss[x - 1] && rr[x - 1]) {
      ss[x - 1] = rr[x - 1] = 0;
      s--;
    }
  }

  int res = 0;

  for (int i = 0; i < n; ++i) {
    if (!ss[i]) continue;

    if (i > 0 && rr[i - 1]) {
      res++;
      rr[i - 1] = 0;
      continue;
    }

    if (i + 1 < n && rr[i + 1]) {
      res++;
      rr[i + 1] = 0;
    }
  }

  std::cout << s - res << "\n";
}