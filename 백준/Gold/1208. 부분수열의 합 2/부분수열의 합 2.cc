#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using TP = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n, s;
  std::cin >> n >> s;
  std::vector<int> a, b;
  int x;
  for (int i = 0; i < n / 2; ++i) {
    std::cin >> x;
    a.push_back(x);
  }
  for (int i = n / 2; i < n; ++i) {
    std::cin >> x;
    b.push_back(x);
  }

  std::vector<i64> bb;
  int p = a.size(), q = b.size();
  for (int br = 0; br < (1 << q); ++br) {
    i64 sum = 0;
    for (int i = 0; i < q; ++i) {
      if (br & (1 << i)) {
        sum += b[i];
      }
    }
    bb.push_back(sum);
  }
  std::ranges::sort(bb);

  i64 ans = 0;
  for (int br = 0; br < (1 << p); ++br) {
    i64 sum = 0;
    for (int i = 0; i < p; ++i) {
      if (br & (1 << i)) {
        sum += a[i];
      }
    }

    ans += std::upper_bound(bb.begin(), bb.end(), s - sum) - std::lower_bound(bb.begin(), bb.end(), s - sum);
  }

  if (s == 0) {
    ans--;
  }
  std::println("{}", ans);
}