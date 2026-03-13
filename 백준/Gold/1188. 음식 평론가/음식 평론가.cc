#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using TP = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n, m;
  std::cin >> n >> m;
  int ans = m - 1;
  int lcm = std::lcm(n, m);
  int a = lcm / n;
  int b = lcm / m;
  int n_lcm = std::lcm(a, b);
  ans -= (lcm / n_lcm - 1);
  std::println("{}", ans);
}