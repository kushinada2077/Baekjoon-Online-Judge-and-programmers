#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  k--;
  std::deque<int> dq;
  for (int i = 1; i <= n; ++i) {
    dq.push_back(i);
  }

  std::cout << "<";
  while (!dq.empty()) {
    for (int i = 0; i < k; ++i) {
      dq.push_back(dq.front());
      dq.pop_front();
    }

    std::cout << dq.front() << ",>"[dq.size() == 1] << " ";
    dq.pop_front();
  }
}