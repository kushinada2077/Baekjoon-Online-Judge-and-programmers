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
  int n, m, x, y, l;
  cin >> n >> m;
  vector<string> a(n);
  for (auto& s : a) cin >> s;
  x = y = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (x == -1 && a[i][j] == '#') {
        y = i;
        x = j;
      }
      if (a[i][j] == '#') l = j - x + 1;
    }
  }

  if (a[y][x + l / 2] == '.') cout << "UP\n";
  if (a[y + l - 1][x + l / 2] == '.') cout << "DOWN\n";
  if (a[y + l / 2][x] == '.') cout << "LEFT\n";
  if (a[y + l / 2][x + l - 1] == '.') cout << "RIGHT\n";
}