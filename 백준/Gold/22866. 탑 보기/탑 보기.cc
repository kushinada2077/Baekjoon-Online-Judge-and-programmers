#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<P> ans_r(n, P(0, -1)), ans_l(n, P(0, -1));
  std::stack<int> s;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = n - 1; i >= 0; --i) {
    while (!s.empty() && a[s.top()] <= a[i]) s.pop();
    ans_r[i].first = (int)s.size();
    if ((int)s.size() > 0) ans_r[i].second = s.top();
    s.push(i);
  }

  while (!s.empty()) s.pop();
  for (int i = 0; i < n; ++i) {
    while (!s.empty() && a[s.top()] <= a[i]) s.pop();
    ans_l[i].first = (int)s.size();
    if ((int)s.size() > 0) ans_l[i].second = s.top();
    s.push(i);
  }

  for (int i = 0; i < n; ++i) {
    auto [l_s, l_i] = ans_l[i];
    auto [r_s, r_i] = ans_r[i];

    if (l_s + r_s == 0) std::cout << "0\n";
    else {
      if (l_i == -1 || (r_i != -1 && std::abs(i - l_i) > std::abs(i - r_i))) std::swap(l_i, r_i);
      std::cout << l_s + r_s << " " << l_i + 1 << "\n";
    }
  }
}