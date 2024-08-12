#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> t(n + 1), p(n + 1), dp(n + 80);
  for (int i = 1; i <= n; ++i) cin >> t[i] >> p[i];
  for (int i = n; i != 0; --i) {
    dp[i] = dp[i + 1];
    if (i + t[i] <= n + 1 && dp[i] < dp[i + t[i]] + p[i]) dp[i] = dp[i + t[i]] + p[i];
  }
  cout << dp[1] << "\n";
}