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
#define INF 0x3f3f3f3f;
using ll = long long;
using namespace std;

const int M = 15746;
int dp[1000005];
int main() {
  fastio;
  int n;
  cin >> n;
  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= n; ++i) dp[i] = (1ll * dp[i - 1] + dp[i - 2]) % M;
  cout << dp[n] << "\n";
}