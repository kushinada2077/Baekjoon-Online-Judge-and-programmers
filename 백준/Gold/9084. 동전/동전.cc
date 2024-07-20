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
#define X first
#define Y second
using namespace std;

// dp[n][k] = k번째 동전부터 금액 n을 만드는 방법의 수
int f(vector<vector<int>>& dp, vector<int>& coin, int n, int k) {
  if (n < 0) return 0;
  if (n == 0) return 1;
  if (dp[n][k] != -1) return dp[n][k];
  int ret = 0;
  for (int i = k; i < si(coin); ++i) ret += f(dp, coin, n - coin[i], i);
  dp[n][k] = ret;
  return ret;
}
int main() {
  fastio;
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> coin(n);
    for (auto& i : coin) cin >> i;
    cin >> m;
    vector<vector<int>> dp(m + 1, vector<int>(n, -1));
    cout << f(dp, coin, m, 0) << "\n";
  }
}