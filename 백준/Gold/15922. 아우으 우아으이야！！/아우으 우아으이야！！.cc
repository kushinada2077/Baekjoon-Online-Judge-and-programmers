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
  std::cin >> n;

  i64 cur_l, cur_r, ans = 0;
  std::cin >> cur_l >> cur_r;
  for (int i = 1; i < n; ++i) {
    i64 l, r;
    std::cin >> l >> r;

    if (l < cur_r) chmax(cur_r, r);
    else {
      ans += cur_r - cur_l;
      cur_l = l;
      cur_r = r;
    }
  }

  ans += cur_r - cur_l;
  std::cout << ans << "\n";
}