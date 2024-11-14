#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
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

const int MOD = 900528;
string s, t;
map<char, int> _hash;

int myPow(int n, int x) {
  int ret = 1;
  while (x) {
    if (x % 2) ret = (1ll * ret * n) % MOD;
    n = (1ll * n * n) % MOD;
    x >>= 1;
  }

  return ret;
}
int main() {
  fastio;
  cin >> s >> t;
  int n = si(s), l = si(t);
  for (int i = 0; i < n; ++i) _hash[s[i]] = i;
  ll ans = 1, nn = n;

  for (int i = 1; i < l; ++i) {
    ans = (ans + nn) % MOD;
    nn = (nn * n) % MOD;
  }

  for (int i = 0; i < l; ++i) {
    ans = (ans + 1ll * myPow(n, l - 1 - i) * _hash[t[i]]) % MOD;
  }

  cout << ans << "\n";
}