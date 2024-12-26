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

// dp[i] = i에서 시작했을 때 가장 가장 큰 부분 배열 합
// dp[i] = max(a[i], dp[i + 1] + a[i])
int tc, n, a[1001], dp[1001];
int solve(int i) {
  if (i == n - 1) return a[i];
  int& ret = dp[i];
  if (ret != -INF) return ret;
  return ret = max(a[i], solve(i + 1) + a[i]);
}
int main() {
  fastio;
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      dp[i] = -INF;
    }

    int ans = -INF;
    for (int i = 0; i < n; ++i) ans = max(ans, solve(i));
    cout << ans << "\n";
  }
}