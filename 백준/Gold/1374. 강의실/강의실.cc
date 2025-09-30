#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

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
  std::vector<P> q;
  for (int i = 0; i < n; ++i) {
    int a, l, r;
    std::cin >> a >> l >> r;
    q.push_back({l, r});
  }

  std::ranges::sort(q);
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    auto [l, r] = q[i];
    if (pq.empty() || pq.top() > l) {
      ans++;
    } else {
      pq.pop();
    }
    pq.push(r);
  }

  std::cout << ans << "\n";
}