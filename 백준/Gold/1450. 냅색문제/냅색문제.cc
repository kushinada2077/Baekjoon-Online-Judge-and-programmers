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
  int n, c;
  std::cin >> n >> c;
  std::vector<i64> a, b;
  for (int i = 0; i < n / 2; ++i) {
    i64 x;
    std::cin >> x;
    a.push_back(x);
  }
  for (int i = n / 2; i < n; ++i) {
    i64 x;
    std::cin >> x;
    b.push_back(x);
  }

  int p = a.size(), q = b.size();
  std::vector<i64> aa, bb;
  for (int brute = 0; brute < (1 << p); ++brute) {
    i64 sum = 0;
    for (int i = 0; i < p; ++i) {
      if (brute & (1 << i)) {
        sum += a[i];
      }
    }
    aa.push_back(sum);
  }

  for (int brute = 0; brute < (1 << q); ++brute) {
    i64 sum = 0;
    for (int i = 0; i < q; ++i) {
      if (brute & (1 << i)) {
        sum += b[i];
      }
    }
    bb.push_back(sum);
  }

  i64 ans = 0;
  for (auto xa : aa) {
    for (auto xb : bb) {
      if (xa + xb <= c) {
        ans++;
      }
    }
  }
  std::println("{}", ans);
}