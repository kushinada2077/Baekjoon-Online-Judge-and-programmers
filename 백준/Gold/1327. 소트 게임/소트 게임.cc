#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using TP = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  auto b = a;
  std::ranges::sort(b);
  std::map<int, int> m, mRev;
  auto c = [&](std::vector<int>& b) {
    int ret = 0;
    for (auto x : b) {
      ret *= 10;
      ret += x;
    }
    return ret;
  };

  auto reverse = [&](int x, int s) {
    std::vector<int> a;
    while (x > 0) {
      a.push_back(x % 10);
      x /= 10;
    }
    std::ranges::reverse(a);

    std::vector<int> b = a;
    /*
    for (int i = s; i < s + k; ++i) {
      b[i] = a[s + k - 1 - (i - s)];
    }
    */
    std::reverse(b.begin() + s, b.begin() + s + k);
    return c(b);
  };

  do {
    int code = c(b);
    m[code] = m.size();
    mRev[int(m.size()) - 1] = code;
  } while (std::next_permutation(b.begin(), b.end()));

  const int S = m[c(a)], T = m[c(b)];
  std::queue<int> que;
  std::vector<int> d(m.size(), -1);
  d[S] = 0;
  que.push(S);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int i = 0; i < n - k + 1; ++i) {
      int v = m[reverse(mRev[u], i)];
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        que.push(v);
      }
    }
  }

  std::println("{}", d[T]);
}