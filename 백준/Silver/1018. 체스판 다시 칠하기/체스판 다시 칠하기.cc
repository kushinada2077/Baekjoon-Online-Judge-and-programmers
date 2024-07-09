#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

int n, m;
int c2i(char& c) { return c == 'W' ? 0 : 1; }
int f(vector<string>& a, int x, int y) {
  int ret = 0;
  for (int i = x; i < x + 8; ++i) {
    for (int j = y; j < y + 8; ++j) {
      if (((i + j) & 1) == c2i(a[i][j])) ret++;
    }
  }
  return min(ret, 64 - ret);
}
int main() {
  fastio;
  cin >> n >> m;
  vector<string> a(n);
  int ans = 0x3f3f3f3f;
  for (auto& i : a) cin >> i;
  for (int i = 0; i < n - 7; ++i) {
    for (int j = 0; j < m - 7; ++j) {
      ans = min(ans, f(a, i, j));
    }
  }
  cout << ans << "\n";
}