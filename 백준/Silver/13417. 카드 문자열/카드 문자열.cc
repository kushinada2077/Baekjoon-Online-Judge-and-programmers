#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

void solve() {
  int n;
  std::cin >> n;
  std::deque<char> dq;
  for (int i = 0; i < n; ++i) {
    char x;
    std::cin >> x;
    if (dq.empty() || dq.front() >= x) {
      dq.push_front(x);
    } else {
      dq.push_back(x);
    }
  }

  for (auto x : dq) {
    std::cout << x;
  }

  std::cout << "\n";
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
}