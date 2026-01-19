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
  std::priority_queue<int> pq;
  int min = 0x3f3f3f3f;

  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    min = std::min(min, a[i]);
    pq.push(a[i] - min);

    std::cout << pq.top() << " \n"[i == n - 1];
  }
}