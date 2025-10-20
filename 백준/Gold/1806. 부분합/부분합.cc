#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  i64 s;
  std::cin >> n >> s;
  int ans = 0x3f3f3f3f;
  std::vector<i64> pref = {0};
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    pref.push_back(pref.back() + x);
    if (pref.back() < s) continue;
    int j = std::upper_bound(pref.begin(), pref.end(), pref.back() - s) - pref.begin();
    ans = std::min(ans, i - j + 2);
  }

  if (ans == 0x3f3f3f3f) ans = 0;
  std::cout << ans << "\n";
}