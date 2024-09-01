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

int dp[10005];
int n, k;
int main() {
  fastio;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= k; ++i) {
    dp[i] = INF;
    for (int j = 1; j <= n; ++j) {
      if (i - a[j] >= 0) dp[i] = min(dp[i], dp[i - a[j]] + 1);
    }
  }
  if (dp[k] == INF) cout << "-1\n";
  else cout << dp[k] << "\n";
}