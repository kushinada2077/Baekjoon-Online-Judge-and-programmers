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

int n, A[1010], dp[1010], dpRev[1010];
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i];

  for (int i = 0; i < n; ++i) {
    dp[i] = 1;
    for (int j = i - 1; j >= 0; --j) {
      if (A[j] < A[i]) dp[i] = max(dp[i], dp[j] + 1);
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    dpRev[i] = 1;
    for (int j = i + 1; j < n; ++j) {
      if (A[i] > A[j]) dpRev[i] = max(dpRev[i], dpRev[j] + 1);
    }
  }

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    ans = max(ans, dp[i] + dpRev[i] - 1);
  }

  cout << ans << "\n";
}