#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <tuple>
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

int f(vector<int>& dp, int n) {
  if (n == 0 || n == 1) return dp[n];
  else if (dp[n] != -1) return dp[n];
  else {
    dp[n] = f(dp, n - 2) + f(dp, n - 1);
    return dp[n];
  }
}
int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> dp(n + 1, -1);
  dp[0] = 0;
  dp[1] = 1;
  cout << f(dp, n) << "\n";
}