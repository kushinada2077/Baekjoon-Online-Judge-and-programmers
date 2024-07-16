#include <algorithm>
#include <deque>
#include <iostream>
#include <unordered_set>
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

const int mod = 1e9 + 7;
int fac(ll a) {
  if (a == 0) return 1;
  return a * fac(a - 1) % mod;
}
int my_pow(ll a, ll b) {
  ll ret = 1;
  while (b > 0) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return ret % mod;
}
int inverse(ll a) { return my_pow(a, mod - 2); }
int main() {
  fastio;
  ll n, k;
  cin >> n >> k;
  ll nf = fac(n), n_kf = fac(n - k), kf = fac(k);
  cout << ((nf * inverse(n_kf)) % mod) * inverse(kf) % mod << "\n";
};