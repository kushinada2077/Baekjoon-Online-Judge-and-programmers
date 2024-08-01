#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

vector<int> f(int n) {
  vector<int> ret;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      ret.pb(i);
      ret.pb(n / i);
    }
    if (i * i == n) ret.pop_back();
  }
  sort(all(ret));
  return ret;
}
int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  sort(all(a));
  vector<int> b;
  for (int i = 1; i < n; ++i) b.pb(a[i] - a[i - 1]);
  int res = b[0];
  for (int i = 1; i < si(b); ++i) res = gcd(res, b[i]);
  vector<int> c = f(res);
  for (int i = 1; i < si(c); ++i) cout << c[i] << " ";
}