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
using namespace std;

int main() {
  fastio;
  ll m, n;
  cin >> m >> n;
  vector<bool> d(1000005, true);
  d[1] = false;

  for (ll i = 2; i <= n; ++i) {
    if (!d[i]) continue;
    for (ll j = i * i; j <= n; j += i) d[j] = false;
    if (i >= m) cout << i << "\n";
  }
}