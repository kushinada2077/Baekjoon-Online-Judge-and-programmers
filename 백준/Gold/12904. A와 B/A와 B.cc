#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s, t;
  std::cin >> s >> t;

  while (s.size() != t.size()) {
    if (t.back() == 'A') t.pop_back();
    else if (t.back() == 'B') {
      t.pop_back();
      std::ranges::reverse(t);
    }
  }

  if (s == t) std::cout << "1\n";
  else std::cout << "0\n";
}