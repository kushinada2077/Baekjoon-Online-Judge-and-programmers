#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  std::vector<std::string> ss(4);
  std::vector<std::deque<int>> dqs(4);
  for (int i = 0; i < 4; ++i) {
    std::cin >> ss[i];
    for (auto c : ss[i]) {
      dqs[i].push_back(c - '0');
    }
    dqs[i].push_back(dqs[i].front());
    dqs[i].pop_front();
    dqs[i].push_back(dqs[i].front());
    dqs[i].pop_front();
  }

  auto rotate = [&](auto&& rotate, int i, int dir, int hou) -> void {
    auto& dq = dqs[i];
    auto l = dq[4];
    auto r = dq[0];
    if (dir == 1) {
      dq.push_front(dq.back());
      dq.pop_back();
      if (i + 1 < 4 && r != dqs[i + 1][4] && (hou == 1 || hou == 2)) {
        rotate(rotate, i + 1, dir ^ 1, 1);
      }
      if (i - 1 >= 0 && l != dqs[i - 1][0] && (hou == 0 || hou == 2)) {
        rotate(rotate, i - 1, dir ^ 1, 0);
      }
    }
    if (dir == 0) {
      dq.push_back(dq.front());
      dq.pop_front();
      if (i + 1 < 4 && r != dqs[i + 1][4] && (hou == 1 || hou == 2)) {
        rotate(rotate, i + 1, dir ^ 1, 1);
      }
      if (i - 1 >= 0 && l != dqs[i - 1][0] && (hou == 0 || hou == 2)) {
        rotate(rotate, i - 1, dir ^ 1, 0);
      }
    }
  };

  int k;
  std::cin >> k;
  for (int i = 0; i < k; ++i) {
    int x, dir;
    std::cin >> x >> dir;
    if (dir == -1) {
      dir = 0;
    }
    x--;
    rotate(rotate, x, dir, 2);
  }
  int ans = 0;

  for (int i = 0; i < 4; ++i) {
    if (dqs[i][6] == 1) {
      ans += (1 << i);
    }
  }
  std::println("{}", ans);
}