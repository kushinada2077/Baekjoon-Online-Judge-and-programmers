#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

int main() {
  fastio;
  int n, m, len = -1;
  cin >> n >> m;
  vector<string> a(n);
  vector<int> r(n, 0);
  vector<int> c(m, 0);
  for (auto& s : a) cin >> s;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '#') {
        r[i]++;
        c[j]++;
        len = max(len, r[i]);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    if (r[i] == len - 1) {
      if (i + len - 1 < n && r[i + len - 1] == len) cout << "UP\n";
      else cout << "DOWN\n";
      return 0;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (c[i] == len - 1) {
      if (i + len - 1 < m && c[i + len - 1] == len) cout << "LEFT\n";
      else cout << "RIGHT\n";
      return 0;
    }
  }
}