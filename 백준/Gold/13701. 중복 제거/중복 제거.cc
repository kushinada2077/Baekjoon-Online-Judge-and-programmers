#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::bitset<1 << 25> a;
  int x;
  while (std::cin >> x) {
    if (a[x] == true) continue;
    std::cout << x << " ";
    a[x] = true;
  }
}