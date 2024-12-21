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

const int MX = 1500001;
// dp[x] = x일부터 상담을 시작했을 때 얻을 수 있는 최대 수익
int n, dp[MX], nxt[MX], p[MX];

int maxProfit(int x) {
  if (x == n) return 0;
  if (x > n) return -INF;
  int& ret = dp[x];
  if (ret != -1) return ret;
  ret = maxProfit(x + 1);
  if (nxt[x] <= n) ret = max(ret, p[x] + maxProfit(nxt[x]));
  return ret;
}

int main() {
  fastio;
  cin >> n;
  fill(dp, dp + n + 1, -1);
  for (int i = 0; i < n; ++i) {
    cin >> nxt[i] >> p[i];
    nxt[i] += i;
  }

  cout << maxProfit(0) << "\n";
}