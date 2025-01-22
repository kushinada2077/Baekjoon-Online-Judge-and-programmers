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

const int MOD = 1e9;
int n;
ll dp[101][10];
ll f(int x, int y) {
  ll& ret = dp[x][y];
  if (ret != -1) return ret;
  if (y == 0) return ret = f(x - 1, 1) % MOD;
  if (y == 9) return ret = f(x - 1, 8) % MOD;
  return ret = (f(x - 1, y - 1) + f(x - 1, y + 1)) % MOD;
}
int main() {
  fastio;
  cin >> n;
  fill(&dp[0][0], &dp[0][0] + 101 * 10, -1);
  dp[1][0] = 0;
  fill(&dp[1][1], &dp[1][1] + 9, 1);
  ll ans = 0;
  for (int i = 0; i < 10; ++i) ans = (ans + f(n, i)) % MOD;
  cout << ans << "\n";
}