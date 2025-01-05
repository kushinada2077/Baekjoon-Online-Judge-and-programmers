#include <bits/stdc++.h>

std::map<std::string, int> nl;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> r;
  std::vector rp(0, std::vector<std::string>());
  for (int i = 0; i < n; ++i) {
    std::string name;
    int l;
    std::cin >> l >> name;
    nl[name] = l;

    int rn = -1;
    for (int i = 0; i < r.size(); ++i) {
      if (r[i] - 10 <= l && l <= r[i] + 10 && rp[i].size() < m) {
        rn = i;
        break;
      }
    }

    if (rn == -1) {
      r.push_back(l);
      std::vector<std::string> nn = {name};
      rp.push_back(nn);
    } else {
      rp[rn].push_back(name);
    }
  }

  for (int i = 0; i < r.size(); ++i) {
    if (rp[i].size() == m) std::cout << "Started!\n";
    else std::cout << "Waiting!\n";
    std::sort(rp[i].begin(), rp[i].end());
    for (auto n : rp[i]) {
      std::cout << nl[n] << " " << n << "\n";
    }
  }
}