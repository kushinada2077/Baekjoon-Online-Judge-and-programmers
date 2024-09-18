#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
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

int dp[105][100005];
int main() {
  fastio;
  int n, k, w, v;
  cin >> n >> k;
  vector<pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].X >> a[i].Y;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - a[i].X >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].X] + a[i].Y);
    }
  }

  cout << dp[n][k] << "\n";
}