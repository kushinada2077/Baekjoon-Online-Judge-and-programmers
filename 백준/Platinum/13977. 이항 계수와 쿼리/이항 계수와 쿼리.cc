#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
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

const int MOD = 1e9 + 7;
int m, fac[4000001];

int myPow(int x, int n) {
  int ret = 1;
  while (n) {
    if (n % 2) ret = 1ll * ret * x % MOD;
    x = 1ll * x * x % MOD;
    n >>= 1;
  }

  return ret;
}

int main() {
  fastio;
  cin >> m;

  fac[0] = 1;
  for (int i = 1; i < 4000001; ++i) fac[i] = 1ll * i * fac[i - 1] % MOD;
  for (int n, k, i{}; i < m; ++i) {
    cin >> n >> k;
    int nf = fac[n], nkf = fac[n - k], kf = fac[k];
    cout << (1ll * nf * myPow(nkf, MOD - 2) % MOD) * myPow(kf, MOD - 2) % MOD << "\n";
  }
}