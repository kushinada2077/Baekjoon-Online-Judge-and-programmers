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

  int a, b, c, d;
  std::cin >> a >> b >> c >> d;

  i64 gcd = std::gcd(b, d);
  i64 lcm = b * d / gcd;

  i64 e = a * lcm / b + c * lcm / d;
  gcd = std::gcd(e, lcm);

  std::cout << e / gcd << " " << lcm / gcd << "\n";
}