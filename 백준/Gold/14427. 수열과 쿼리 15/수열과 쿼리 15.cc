#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::priority_queue<P, std::vector<P>, std::greater<P>> pq, lazy;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    pq.push({a[i], i});
  }
  int m;
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    int q;
    std::cin >> q;
    if (q == 1) {
      int idx, v;
      std::cin >> idx >> v;
      lazy.push({a[idx - 1], idx - 1});
      a[idx - 1] = v;
      pq.push({v, idx - 1});
    } else if (q == 2) {
      while (!pq.empty() && !lazy.empty() && pq.top() == lazy.top()) {
        pq.pop();
        lazy.pop();
      }

      std::cout << pq.top().second + 1 << "\n";
    }
  }
}