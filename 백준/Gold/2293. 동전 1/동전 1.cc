#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
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

int n, k, arr[101], dp[10001];
int main() {
  fastio;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> arr[i + 1];

  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (j >= arr[i]) dp[j] += dp[j - arr[i]];
    }
  }

  cout << dp[k] << "\n";
}