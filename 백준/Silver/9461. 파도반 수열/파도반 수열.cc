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

int n;
ll dp[101];
int main() {
  fastio;
  cin >> n;
  dp[1] = dp[2] = dp[3] = 1;
  dp[4] = dp[5] = 2;

  for (int i = 6; i <= 100; ++i) dp[i] = dp[i - 1] + dp[i - 5];
  for (int x; n; --n) {
    cin >> x;
    cout << dp[x] << "\n";
  }
}