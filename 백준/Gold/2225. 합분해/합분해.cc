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

const int MOD = 1e9;
// dp[i][j] = i개의 [0, j] 범위의 수를 더했을 때 합이 j인 경우의 수
int n, k, dp[201][201];
int main() {
  fastio;
  cin >> n >> k;
  for (int i = 0; i <= n; ++i) dp[1][i] = 1;
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int l = 0; l <= j; ++l) {
        dp[i][j] = (1ll * dp[i][j] + dp[i - 1][j - l]) % MOD;
      }
    }
  }

  cout << dp[k][n] << "\n";
}