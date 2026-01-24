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
  const int MAX = 1501;
  std::vector<int> abc(3);
  std::cin >> abc[0] >> abc[1] >> abc[2];
  std::sort(abc.begin(), abc.end());

  int a = abc[0], b = abc[1], c = abc[2];
  if ((a + b + c) % 3) {
    std::cout << "0\n";
    return 0;
  }

  int sum = a + b + c;
  int x = sum / 3;
  std::vector vis(MAX, std::vector<bool>(MAX));
  std::queue<std::vector<int>> q;
  q.push({a, b});
  vis[a][b] = true;

  while (!q.empty()) {
    auto cur = q.front();
    int c = sum - (a + b);
    q.pop();

    std::vector<int> tmp = {cur[0], cur[1], sum - (cur[0] + cur[1])};
    std::sort(tmp.begin(), tmp.end());

    for (int i = 0; i < 3; ++i) {
      for (int j = i + 1; j < 3; ++j) {
        if (tmp[i] == tmp[j]) continue;
        std::vector<int> n_tmp(3);
        for (int k = 0; k < 3; ++k) {
          if (k != i && k != j) n_tmp[2] = tmp[k];
        }

        n_tmp[0] = 2 * tmp[i];
        n_tmp[1] = tmp[j] - tmp[i];
        std::sort(n_tmp.begin(), n_tmp.end());
        if (n_tmp[0] >= MAX || n_tmp[1] >= MAX || n_tmp[2] >= MAX) continue;
        if (vis[n_tmp[0]][n_tmp[1]]) continue;
        q.push(n_tmp);
        vis[n_tmp[0]][n_tmp[1]] = true;
      }
    }
  }

  if (vis[x][x] == true) {
    std::cout << "1\n";
  } else {
    std::cout << "0\n";
  }
}