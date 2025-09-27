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

  int ans = 0;
  std::vector<int> cnt(26);
  std::set<char> a_list;

  for (int i = 0, j = 0; i < (int)s.size(); ++i) {
    cnt[s[i] - 'a']++;
    a_list.insert(s[i]);
    while ((int)a_list.size() > n) {
      if (--cnt[s[j] - 'a'] == 0) {
        a_list.erase(s[j]);
      }
      j++;
    }

    chmax(ans, i - j + 1);
  }

  std::cout << ans << "\n";
}