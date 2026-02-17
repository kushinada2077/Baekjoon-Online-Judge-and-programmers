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
  std::string s, p;
  std::cin >> s >> p;
  int n = s.size();
  int ans = 0;
  int m = p.size();
  for (int i = 0; i < m;) {
    int len = 0;
    for (int j = 0; j < n; ++j) {
      int k = i;
      int l = j;
      while (k < m && l < n && p[k] == s[l]) {
        k++;
        l++;
      }
      len = std::max(len, l - j);
    }

    ans++;
    i += len;
  }

  std::cout << ans << "\n";
}