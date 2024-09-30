#include <algorithm>
#include <iostream>
#include <queue>
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

const int MX = 20;
int cost[MX][MX], dp[MX][MX];
bool chk[MX][MX];
int main() {
  fastio;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> cost[i][j];
    }
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == k || j == k) continue;
        if (cost[i][j] > cost[i][k] + cost[k][j]) {
          cout << "-1\n";
          return 0;
        } else if (cost[i][j] == cost[i][k] + cost[k][j]) chk[i][j] = 1;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!chk[i][j]) ans += cost[i][j];
    }
  }
  cout << ans / 2 << "\n";
}