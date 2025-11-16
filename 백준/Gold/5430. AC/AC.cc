#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

std::vector<std::string> split(std::string s, std::string sep) {
  int n = (int)s.size();
  std::vector<std::string> ret;
  int p_idx = 0;
  while (p_idx < n) {
    int n_idx = s.find(sep, p_idx);
    if (n_idx == std::string::npos) break;
    ret.push_back(s.substr(p_idx, n_idx - p_idx));
    p_idx = n_idx + 1;
  }

  ret.push_back(s.substr(p_idx));
  return ret;
}
void solve() {
  std::string p, a;
  std::cin >> p;
  int n;
  std::cin >> n >> a;
  auto b = split(a.substr(1, (int)a.size() - 2), ",");
  std::vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    c[i] = std::stoi(b[i]);
  }

  int l = 0, r = n - 1;
  bool rev = false;
  for (auto c : p) {
    if (c == 'R') rev = !rev;
    else if (c == 'D') {
      if (l > r) {
        std::cout << "error\n";
        return;
      }
      if (rev == false) l++;
      else r--;
    }
  }

  std::cout << "[";
  if (rev == false)
    for (int i = l; i <= r; ++i) {
      std::cout << c[i];
      if (i != r) std::cout << ",";
    }
  else
    for (int i = r; i >= l; --i) {
      std::cout << c[i];
      if (i != l) std::cout << ",";
    }

  std::cout << "]\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
}