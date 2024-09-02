#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

vector<vector<int>> d(25, vector<int>(25, 0));
vector<vector<bool>> chk(25, vector<bool>(25, 0));
int main() {
  fastio;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) cin >> d[i][j];
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (d[i][j] > d[i][k] + d[k][j]) {
          cout << "-1\n";
          return 0;
        }
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      bool f = true;
      for (int k = 1; k <= n; ++k) {
        if (k == i || k == j) continue;
        if (d[i][k] + d[k][j] == d[i][j]) {
          f = false;
          break;
        }
      }
      if (f) chk[i][j] = 1;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j)
      if (chk[i][j]) ans += d[i][j];
  }
  cout << ans << "\n";
}