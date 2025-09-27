#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

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
  std::string s;
  std::cin >> n >> s;

  int ans = 0, kind = 0;
  std::vector<int> cnt(26);

  for (int i = 0, j = 0; i < (int)s.size(); ++i) {
    if (cnt[s[i] - 'a']++ == 0) kind++;
    while (kind > n) {
      if (--cnt[s[j] - 'a'] == 0) {
        kind--;
      }
      j++;
    }

    chmax(ans, i - j + 1);
  }

  std::cout << ans << "\n";
}