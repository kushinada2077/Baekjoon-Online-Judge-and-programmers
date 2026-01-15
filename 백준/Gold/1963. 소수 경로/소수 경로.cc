#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

std::vector<bool> prime(10000, true);
void solve() {
  int a, b;
  std::cin >> a >> b;

  std::queue<int> q;
  std::vector<int> dist(10000, -1);
  q.push(a);
  dist[a] = 0;

  while (!q.empty()) {
    int u_copy = q.front();
    int u = u_copy;
    q.pop();

    std::vector<int> digit;
    while (u_copy > 0) {
      digit.push_back(u_copy % 10);
      u_copy /= 10;
    }

    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 10; ++j) {
        auto new_digit = digit;
        new_digit[i] = (digit[i] + j) % 10;

        int v = 0;
        for (int k = 0, ten = 1; k < 4; ++k, ten *= 10) {
          v += ten * new_digit[k];
        }

        if (v < 1000 || 9999 < v) continue;
        if (!prime[v] || dist[v] != -1) continue;

        q.push(v);
        dist[v] = dist[u] + 1;
      }
    }
  }

  if (dist[b] != -1) {
    std::cout << dist[b] << "\n";
  } else {
    std::cout << "Impossible\n";
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int t;
  std::cin >> t;

  prime[2] = true;
  for (int i = 2; i * i < 10000; ++i) {
    for (int j = i * i; j < 10000; j += i) {
      prime[j] = false;
    }
  }

  while (t--) {
    solve();
  }
}