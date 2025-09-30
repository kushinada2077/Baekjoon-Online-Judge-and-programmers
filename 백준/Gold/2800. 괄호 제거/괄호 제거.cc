#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  int n = (int)s.size();

  std::stack<int> stack;
  std::vector<int> hash(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') stack.push(i);
    else if (s[i] == ')') {
      hash[stack.top()] = i;
      stack.pop();
    }
  }

  std::vector<int> bit(n, 0);
  std::vector<std::string> ans;
  auto dfs = [&](auto&& dfs, int k) {
    if (k == n) {
      std::string ss = "";
      for (int i = 0; i < n; ++i) {
        if (bit[i] == 1) continue;
        else ss += s[i];
      }
      ans.push_back(ss);

      return;
    }

    if (s[k] == '(') {
      dfs(dfs, k + 1);
      bit[k] = bit[hash[k]] = 1;
      dfs(dfs, k + 1);
      bit[k] = bit[hash[k]] = 0;
    } else {
      dfs(dfs, k + 1);
    }
  };

  dfs(dfs, 0);
  std::ranges::sort(ans);
  ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
  for (auto ss : ans) {
    if (s == ss) continue;
    std::cout << ss << "\n";
  }
}