#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

template <class T, class U>
inline bool chmax(T& a, const U& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  int max_len = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    chmax(max_len, (int)a[i].size());
  }

  for (int l = max_len; l >= 0; --l) {
    std::map<std::string, int> h;
    std::set<std::string> ans_prefix;
    for (int i = 0; i < n; ++i) {
      std::string prefix = a[i].substr(0, std::min((int)a[i].size(), l));
      if (h[prefix] == 1) ans_prefix.insert(prefix);
      h[prefix]++;
    }

    if (!ans_prefix.empty()) {
      int j;
      std::string pre;
      for (j = 0; j < n; ++j) {
        std::string prefix = a[j].substr(0, std::min((int)a[j].size(), l));
        if (ans_prefix.contains(prefix)) {
          pre = prefix;
          std::cout << a[j] << "\n";
          break;
        }
      }

      for (int k = j + 1; k < n; ++k) {
        if (a[k].starts_with(pre)) {
          std::cout << a[k] << "\n";
          break;
        }
      }

      return 0;
    }
  }
}