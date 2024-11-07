#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
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

const int MOD = 9901;
int dp[100005];
int main() {
  fastio;
  int n;
  cin >> n;

  dp[1] = 3;
  dp[2] = 7;

  for (int i = 3; i <= n; ++i) {
    dp[i] = (2ll * dp[i - 1] + dp[i - 2]) % MOD;
  }

  cout << dp[n] << "\n";
}