#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<i64, int>;

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
  int n, m;
  std::cin >> n >> m;
  std::vector<i64> t(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> t[i];
  }

  i64 ans = 0;
  std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
  std::ranges::sort(t, std::greater<i64>());
  for (int i = 0; i < m; ++i) pq.push({0, i});

  for (int i = 0; i < n; ++i) {
    auto [time, idx] = pq.top();
    pq.pop();

    chmax(ans, time);
    pq.push({time + t[i], idx});
  }

  while (!pq.empty()) {
    auto [time, idx] = pq.top();
    pq.pop();
    chmax(ans, time);
  }

  std::cout << ans << "\n";
}