#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::pair<std::string, int>> a(n);
  std::vector<std::string> b(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i].first;
    a[i].second = i;
    b[i] = a[i].first;
  }

  auto common_prefix_len = [&](const std::string& s, const std::string& t) {
    int n = std::min((int)s.size(), (int)t.size());
    for (int i = 0; i < n; ++i) {
      if (s[i] != t[i]) return i;
    }

    return n;
  };

  std::ranges::sort(a);

  std::string prefix = "";
  int idx = 0x3f3f3f3f;
  for (int i = 0; i < n - 1; ++i) {
    auto [s1, idx1] = a[i];
    auto [s2, idx2] = a[i + 1];
    int l = common_prefix_len(s1, s2);
    if ((int)prefix.size() < l) {
      prefix = s1.substr(0, l);
      idx = std::min(idx1, idx2);
    } else if ((int)prefix.size() == l && std::min(idx1, idx2) < idx) {
      prefix = s1.substr(0, l);
      idx = std::min(idx1, idx2);
    }
  }

  for (int i = 0, cnt = 0; i < n && cnt < 2; ++i) {
    if (b[i].starts_with(prefix)) {
      std::cout << b[i] << "\n";
      cnt++;
    }
  }
}