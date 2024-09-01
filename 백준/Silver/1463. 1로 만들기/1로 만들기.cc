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
using ll = long long;
using namespace std;

const int INF = 0x3f3f3f3f;

vector<int> dp(1000005, INF);

int main() {
  fastio;
  int x;
  cin >> x;
  dp[1] = 0;
  for (int i = 1; i < x; ++i) {
    dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    if (2 * i <= x) dp[2 * i] = min(dp[2 * i], dp[i] + 1);
    if (3 * i <= x) dp[3 * i] = min(dp[3 * i], dp[i] + 1);
  }
  cout << dp[x] << "\n";
}