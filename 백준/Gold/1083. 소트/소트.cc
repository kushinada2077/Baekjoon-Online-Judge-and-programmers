#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int s;
  std::cin >> s;

  for (int i = 0; i < n && s > 0; ++i) {
    int max_i = i, left = s;
    for (int j = i + 1; j < n && left > 0; ++j, --left) {
      if (a[max_i] < a[j]) max_i = j;
    }
    int tmp = a[max_i];
    a.erase(a.begin() + max_i);
    a.insert(a.begin() + i, tmp);
    s -= max_i - i;
  }

  for (int i = 0; i < n; ++i) {
    std::cout << a[i] << " \n"[i == n - 1];
  }
}