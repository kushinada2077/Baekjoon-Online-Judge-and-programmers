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
  const int MAX = 8000001;
  const int offset = 4000000;
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

  std::vector<int> bb(MAX);
  int p = a.size(), q = b.size();
  for (int br = 0; br < (1 << q); ++br) {
    int sum = 0;
    for (int i = 0; i < q; ++i) {
      if (br & (1 << i)) {
        sum += b[i];
      }
    }
    bb[sum + offset]++;
  }

  i64 ans = 0;
  for (int br = 0; br < (1 << p); ++br) {
    int sum = 0;
    for (int i = 0; i < p; ++i) {
      if (br & (1 << i)) {
        sum += a[i];
      }
    }

    ans += bb[s - sum + offset];
  }

  if (s == 0) {
    ans--;
  }
  std::println("{}", ans);
}