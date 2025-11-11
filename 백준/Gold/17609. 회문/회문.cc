#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using P_i64 = std::pair<i64, i64>;

int is_pal(std::string& s, int l, int r, bool chance) {
  if (l >= r) {
    if (chance == false) return 1;
    else return 0;
  }
  if (!chance && s[l] != s[r]) return 2;
  if (chance && s[l] != s[r]) return std::min(is_pal(s, l + 1, r, false), is_pal(s, l, r - 1, false));
  return is_pal(s, l + 1, r - 1, chance);
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    std::string s;
    std::cin >> s;
    std::cout << is_pal(s, 0, (int)s.size() - 1, true) << "\n";
  }
}