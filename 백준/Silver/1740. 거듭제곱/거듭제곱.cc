#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

ll my_pow(ll a, int b) {
  ll ret = 1;
  while (b > 0) {
    if (b % 2) ret *= a;
    a *= a;
    b /= 2;
  }
  return ret;
}
int main() {
  fastio;
  ll n;
  cin >> n;
  ll ans = 0, a = 1;

  while (n > 0) {
    if (n % 2) ans += a;
    a *= 3;
    n /= 2;
  }
  cout << ans << "\n";
}