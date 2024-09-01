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

const int M = 10007;
int f(int x) {
  if (x == 0) return 1;
  return (1ll * x * f(x - 1)) % M;
}
int my_pow(int a, int x) {
  int ret = 1;
  while (x) {
    if (x & 1) ret = (ret * a) % M;
    a = (a * a) % M;
    x >>= 1;
  }
  return ret;
}
int dp[1005][10];
int main() {
  fastio;
  int n, k;
  cin >> n >> k;
  int nf = f(n), kf = my_pow(f(k), M - 2), nkf = my_pow(f(n - k), M - 2);
  cout << ((1ll * nf * kf) % M * nkf) % M << "\n";
}