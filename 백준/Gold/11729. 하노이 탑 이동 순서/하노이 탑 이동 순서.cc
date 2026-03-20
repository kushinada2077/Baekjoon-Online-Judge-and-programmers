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
  int n;
  std::cin >> n;

  auto hanoi = [&](auto&& hanoi, int k, int f, int t, int b) {
    if (k == 1) {
      std::println("{} {}", f, t);
      return;
    }
    hanoi(hanoi, k - 1, f, b, t);
    hanoi(hanoi, 1, f, t, b);
    hanoi(hanoi, k - 1, b, t, f);
  };

  std::println("{}", (1 << n) - 1);
  hanoi(hanoi, n, 1, 3, 2);
}