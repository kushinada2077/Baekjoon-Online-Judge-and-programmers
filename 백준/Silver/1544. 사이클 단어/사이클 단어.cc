#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  auto same = [&](std::string& a, std::string& b) {
    if (a.size() != b.size()) {
      return false;
    }

    int length = a.size();
    for (int i = 0; i < length; ++i) {
      bool ok = true;
      for (int j = 0; j < length; ++j) {
        if (a[(i + j) % length] != b[j]) {
          ok = false;
          break;
        }
      }

      if (ok) {
        return true;
      }
    }

    return false;
  };

  int ans = 0;
  std::vector<bool> chk(n);
  for (int i = 0; i < n; ++i) {
    if (chk[i] == true) {
      continue;
    }
    ans++;
    for (int j = i + 1; j < n; ++j) {
      if (chk[j] == true) {
        continue;
      }
      if (same(a[i], a[j])) {
        chk[j] = true;
      }
    }
  }

  std::cout << ans << "\n";
}