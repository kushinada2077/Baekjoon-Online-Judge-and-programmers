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

int dp[100005];
int main() {
  fastio;
  int n;
  cin >> n;
  fill(dp, dp + 100005, INF);
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j * j <= i; ++j) {
      dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
  }
  cout << dp[n] << "\n";
}