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
  std::string line;
  std::getline(std::cin, line);

  std::istringstream iss(line);
  i64 x;
  std::vector<i64> a;
  while (iss >> x) a.push_back(x);

  i64 ans = 1;
  int n = (int)a.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ans = std::max(ans, std::gcd(a[i], a[j]));
    }
  }

  std::cout << ans << "\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int t;
  std::cin >> t;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  while (t--) {
    solve();
  }
}