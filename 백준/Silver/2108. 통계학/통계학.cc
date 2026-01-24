#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  int sum = 0;
  int max_cnt = 0;
  std::map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    sum += a[i];
    cnt[a[i]]++;
    max_cnt = std::max(max_cnt, cnt[a[i]]);
  }

  std::sort(a.begin(), a.end());
  std::vector<int> b;
  for (auto [k, v] : cnt) {
    if (v == max_cnt) b.push_back(k);
  }

  int res = std::round((float)sum / n) + 0.0;
  std::cout << res << "\n";
  std::cout << a[n / 2] << "\n";
  if ((int)b.size() == 1) {
    std::cout << b.front() << "\n";
  } else {
    std::cout << b[1] << "\n";
  }
  std::cout << a.back() - a.front() << "\n";
}