#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k, r;
  std::cin >> n >> k >> r;
  std::vector impossible(n * n, std::set<int>());
  for (int i = 0; i < r; ++i) {
    int r, c, rr, cc;
    std::cin >> r >> c >> rr >> cc;
    r--;
    c--;
    rr--;
    cc--;
    impossible[r * n + c].insert(rr * n + cc);
    impossible[rr * n + cc].insert(r * n + c);
  }

  std::vector<int> cow;
  for (int i = 0; i < k; ++i) {
    int r, c;
    std::cin >> r >> c;
    r--;
    c--;
    cow.push_back(r * n + c);
  }

  int ans = 0;
  for (int i = 0; i < k; ++i) {
    ans += [&]() {
      std::queue<int> q;
      std::vector<int> vis(n * n);
      q.push(cow[i]);
      vis[cow[i]] = 1;

      while (!q.empty()) {
        int u = q.front();
        q.pop();

        int d[4] = {1, -1, n, -n};
        for (int dir = 0; dir < 4; ++dir) {
          int y = u / n + "2101"[dir] - '1', x = u % n + "1210"[dir] - '1';
          int v = y * n + x;
          if (y < 0 || y >= n || x < 0 || x >= n || vis[v] == 1 || impossible[u].contains(v)) continue;
          q.push(v);
          vis[v] = 1;
        }
      }

      int ret = 0;
      for (int j = i + 1; j < k; ++j) {
        ret += vis[cow[j]] == 0;
      }

      return ret;
    }();
  }

  std::cout << ans << "\n";
}