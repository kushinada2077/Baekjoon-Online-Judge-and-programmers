#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), c(n), w(m), h(m);
  for (int i = 0; i < n; ++i) {
    std::cin >> c[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cin >> w[i];
  }
  int ans = 0;
  std::queue<int> q;
  for (int i = 0; i < 2 * m; ++i) {
    int o;
    std::cin >> o;
    if (o > 0) {
      o--;
      int l = -1;
      for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
          l = i;
          break;
        }
      }
      if (l == -1 || !q.empty()) {
        q.push(o);
      } else {
        a[l] = 1;
        h[o] = l;
        ans += c[l] * w[o];
      }
    } else {
      o = -o - 1;
      int l = h[o];
      a[l] = 0;
      if (!q.empty()) {
        int b = q.front();
        q.pop();
        a[l] = 1;
        h[b] = l;
        ans += c[l] * w[b];
      }
    }
  }

  std::cout << ans << "\n";
}