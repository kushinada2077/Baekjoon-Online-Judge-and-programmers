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
  std::vector<int> ans;

  while (n != 0) {
    int d = n % -2;
    n /= -2;
    if (d < 0) {
      d += 2;
      n++;
    }

    ans.push_back(d);
  }

  if (ans.empty()) {
    std::cout << "0";
  } else {
    for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
      std::cout << *it;
    }
  }

  std::cout << "\n";
}