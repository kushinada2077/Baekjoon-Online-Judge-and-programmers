
#include <algorithm>
#include <iostream>
#include <set>
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

vector<ll> dp(36, -1);
ll f(int n) {
  if (n == 0) return 1;
  if (dp[n] != -1) return dp[n];
  ll ret = 0;
  for (ll i = 0; i < n / 2; ++i) {
    ret += 2 * (f(i) * f(n - i - 1));
  }
  ll mid = f(n / 2);
  if (n & 1) ret += mid * mid;
  dp[n] = ret;
  return ret;
}
int main() {
  fastio;
  int n;
  cin >> n;
  cout << f(n) << "\n";
}