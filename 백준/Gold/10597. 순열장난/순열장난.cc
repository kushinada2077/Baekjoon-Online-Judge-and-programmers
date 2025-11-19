#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;
using P_i64 = std::pair<i64, i64>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;

  int n = (int)s.size();
  std::vector<int> ans;
  std::vector<bool> chk(51, false);
  auto dfs = [&](auto&& dfs, int k) {
    if (n == k) {
      bool ok = true;
      int cnt = (int)ans.size();
      for (int i = 1; i <= cnt; ++i) {
        if (chk[i] == false) {
          ok = false;
          break;
        }
      }

      if (ok == false) return;

      for (auto x : ans) std::cout << x << " ";
      exit(0);
    }

    for (int len = 1; len <= 2; ++len) {
      if (k + len > n) continue;
      int num = std::stoi(s.substr(k, len));
      if (chk[num] == true) continue;
      chk[num] = true;
      ans.push_back(num);
      dfs(dfs, k + len);
      chk[num] = false;
      ans.pop_back();
    }
  };

  dfs(dfs, 0);
}