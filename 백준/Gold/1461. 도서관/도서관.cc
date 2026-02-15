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
  int n, m;
  std::cin >> n >> m;
  std::priority_queue<int> l, r;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (x > 0) r.push(x);
    else l.push(-x);
  }

  int ans = 0;
  if (!l.empty() && !r.empty()) {
    if (l.top() > r.top()) {
      ans += l.top();
      for (int i = 0; !l.empty() && i < m; ++i) {
        l.pop();
      }
    } else {
      ans += r.top();
      for (int i = 0; !r.empty() && i < m; ++i) {
        r.pop();
      }
    }
  } else if (!l.empty()) {
    ans += l.top();
    for (int i = 0; !l.empty() && i < m; ++i) {
      l.pop();
    }
  } else if (!r.empty()) {
    ans += r.top();
    for (int i = 0; !r.empty() && i < m; ++i) {
      r.pop();
    }
  }

  while (!l.empty()) {
    ans += 2 * l.top();
    for (int i = 0; !l.empty() && i < m; ++i) {
      l.pop();
    }
  }

  while (!r.empty()) {
    ans += 2 * r.top();
    for (int i = 0; !r.empty() && i < m; ++i) {
      r.pop();
    }
  }

  std::cout << ans << "\n";
}