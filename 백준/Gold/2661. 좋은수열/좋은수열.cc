#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;

  std::string s = "";
  auto ok = [&](std::string& s) {
    int m = (int)s.size();
    if (m == 1) return true;
    int j = m - 1, l = 1;

    while (j - l >= 0) {
      std::string a = s.substr(j);
      std::string b = s.substr(j - l, l);
      if (a == b) return false;
      j--;
      l++;
    }

    return true;
  };
  auto dfs = [&](auto&& dfs, int k) {
    if (n == k) {
      std::cout << s << "\n";
      exit(0);
      return;
    }

    for (int i = 1; i <= 3; ++i) {
      auto tmp = s + std::to_string(i);
      if (ok(tmp)) {
        s += std::to_string(i);
        dfs(dfs, k + 1);
        s.pop_back();
      }
    }

    return;
  };

  dfs(dfs, 0);
}