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
    if (ss[x - 1] == 1 && rr[x - 1] == 1) {
      s--;
      ss[x - 1] = rr[x - 1] = 0;
    }
  }

  int res = 0;
  std::vector<bool> chk(n);

  auto dfs = [&](auto&& dfs, int k, int cnt) {
    if (n == k) {
      res = std::max(res, cnt);
      return;
    }

    if (!ss[k] || rr[k]) dfs(dfs, k + 1, cnt);
    else {
      if (k > 0 && !chk[k - 1] && !ss[k - 1] && rr[k - 1]) {
        chk[k - 1] = true;
        rr[k - 1] = false;
        dfs(dfs, k + 1, cnt + 1);
        chk[k - 1] = false;
        rr[k - 1] = true;
      } else if (k + 1 < n && !chk[k + 1] && !ss[k + 1] && rr[k + 1]) {
        chk[k + 1] = true;
        rr[k + 1] = false;
        dfs(dfs, k + 1, cnt + 1);
        chk[k + 1] = false;
        rr[k + 1] = true;
      } else {
        dfs(dfs, k + 1, cnt);
      }
    }
  };

  dfs(dfs, 0, 0);

  std::cout << s - res << "\n";
}