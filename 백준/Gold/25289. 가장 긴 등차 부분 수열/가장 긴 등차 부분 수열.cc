#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
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
using TP = tuple<int, int, int>;
using P = pair<int, int>;

// dp[n] = 마지막 숫자가 n인 가장 긴 등차부분수열의 길이
int n, ans = 0, A[100001], dp[101];
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i];

  for (int d = -99; d < 100; ++d) {
    fill(dp, dp + 101, 0);
    for (int i = 0; i < n; ++i) {
      if (A[i] - d > 0 && A[i] - d < 101) dp[A[i]] = max(dp[A[i]], dp[A[i] - d] + 1);
      else dp[A[i]] = 1;
      ans = max(ans, dp[A[i]]);
    }
  }

  cout << ans << "\n";
}