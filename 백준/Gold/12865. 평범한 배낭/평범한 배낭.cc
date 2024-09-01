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

int dp[105][100005];
int main() {
  fastio;
  int n, k, w, v;
  cin >> n >> k;
  vector<pair<int, int>> a = {{0, 0}};
  for (int i = 0; i < n; ++i) {
    cin >> w >> v;
    a.pb({w, v});
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (j < a[i].X) dp[i][j] = dp[i - 1][j];
      else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].X] + a[i].Y);
    }
  }
  cout << dp[n][k] << "\n";
}