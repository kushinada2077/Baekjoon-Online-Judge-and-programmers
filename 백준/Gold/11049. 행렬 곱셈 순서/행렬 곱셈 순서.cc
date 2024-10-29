#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define L_PATH "input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using T = tuple<int, int, int>;
using P = pair<int, int>;

// dp[i][j] = i번째부터 j번째까지 곱했을 때 최솟값
int n, dp[501][501], mat[501][2];
int main() {
  fastio;
  cin >> n;
  for (int r, c, i{}; i < n; ++i) {
    cin >> r >> c;
    mat[i + 1][0] = r;
    mat[i + 1][1] = c;
  }

  for (int i = 1; i <= n - 1; ++i) {
    dp[i][i + 1] = mat[i][0] * mat[i][1] * mat[i + 1][1];
  }

  for (int m = 2; m <= n; ++m) {
    for (int i = 1; i <= n - m; ++i) {
      int j = i + m;
      for (int k = i; k < j; ++k) {
        int res = dp[i][k] + dp[k + 1][j] + mat[i][0] * mat[k][1] * mat[j][1];
        if (!dp[i][j] || dp[i][j] > res) dp[i][j] = res;
      }
    }
  }

  cout << dp[1][n] << "\n";
}