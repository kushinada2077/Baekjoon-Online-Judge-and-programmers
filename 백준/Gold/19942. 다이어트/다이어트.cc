#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, mp, mf, ms, mv;
  std::cin >> n >> mp >> mf >> ms >> mv;
  std::vector<int> p(n), f(n), s(n), v(n), c(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
  }

  int ans = 0x3f3f3f3f;
  std::vector<std::vector<int>> ans_list;
  std::vector<int> included;

  auto dfs = [&](auto&& dfs, int k) {
    if (n == k) {
      int sp{}, sf{}, ss{}, sv{}, cost{};
      for (auto i : included) {
        sp += p[i];
        sf += f[i];
        ss += s[i];
        sv += v[i];
        cost += c[i];
      }

      if (sp >= mp && sf >= mf && ss >= ms && sv >= mv && ans >= cost) {
        auto tmp = std::vector<int>(included);
        tmp.insert(tmp.begin(), cost);
        ans_list.push_back(tmp);
        ans = cost;
      }

      return;
    }

    dfs(dfs, k + 1);
    included.push_back(k);
    dfs(dfs, k + 1);
    included.pop_back();
  };

  dfs(dfs, 0);
  std::sort(ans_list.begin(), ans_list.end());

  if (ans_list.empty()) std::cout << "-1\n";
  else {
    std::cout << ans_list.front().front() << "\n";
    for (int i = 1; i < (int)ans_list.front().size(); ++i) {
      std::cout << ans_list.front()[i] + 1 << " ";
    }
  }
}