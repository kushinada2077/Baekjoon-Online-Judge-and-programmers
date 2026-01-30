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
  int n;
  std::cin >> n;
  std::map<std::string, int> S;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    S[s]++;
  }

  auto cnt = [&](std::string s1, std::string s2) {
    int ret = 0;
    for (int i = 0; i < 4; ++i) {
      ret += s1[i] != s2[i];
    }

    return ret;
  };

  int ans = 0x3f3f3f3f;
  std::vector<std::string> a;
  for (auto [k, v] : S) {
    for (int i = 0; i < std::min(3, v); ++i) {
      a.push_back(k);
    }
  }
  int m = (int)a.size();

  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      for (int k = j + 1; k < m; ++k) {
        ans = std::min(ans, cnt(a[i], a[j]) + cnt(a[j], a[k]) + cnt(a[i], a[k]));
      }
    }
  }

  std::cout << ans << "\n";
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
}