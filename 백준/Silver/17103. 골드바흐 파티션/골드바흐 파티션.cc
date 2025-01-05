#include <bits/stdc++.h>

bool notp[1000001];
int f(int n) {
  int l, r, ret = 0;
  l = r = n / 2;
  while (l > 1) {
    if (!notp[l] && !notp[r]) ret++;
    l--;
    r++;
  }

  return ret;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;

  for (int i = 2; i * i <= 1000000; ++i) {
    if (notp[i]) continue;
    for (int j = i * i; j <= 1000000; j += i) {
      notp[j] = true;
    }
  }

  while (t--) {
    int n;
    std::cin >> n;
    std::cout << f(n) << "\n";
  }
}