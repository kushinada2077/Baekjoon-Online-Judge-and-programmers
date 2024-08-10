#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

ll n, m, k, p, q, r;
vector<ll> a, BIT;
ll add(int i) {
  ll ret = 0;
  while (i) {
    ret += BIT[i];
    i -= (i & -i);
  }
  return ret;
}
void update(int i, ll x) {
  while (i <= n) {
    BIT[i] += x;
    i += (i & -i);
  }
}
int main() {
  fastio;
  cin >> n >> m >> k;
  a = vector<ll>(n + 1);
  BIT = vector<ll>(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    update(i, a[i]);
  }
  for (int i = 0; i < k + m; ++i) {
    cin >> p >> q >> r;
    if (p == 1) {
      update(q, r - a[q]);
      a[q] = r;
    } else {
      cout << add(r) - add(q - 1) << "\n";
    }
  }
}