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
  std::vector<std::string> a(n);
  std::map<std::string, int> s2i;

  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    s2i[a[i]] = i;
  }

  int ans = 0;
  std::vector<std::string> b(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> b[i];
  }

  for (int i = 0; i < n; ++i) {
    int ii = s2i[b[i]];
    std::set<std::string> S;
    for (int j = 0; j < ii; ++j) {
      S.insert(a[j]);
    }

    ans += [&] {
      for (int k = i + 1; k < n; ++k) {
        if (S.contains(b[k])) return 1;
      }
      return 0;
    }();
  }

  std::cout << ans << "\n";
}