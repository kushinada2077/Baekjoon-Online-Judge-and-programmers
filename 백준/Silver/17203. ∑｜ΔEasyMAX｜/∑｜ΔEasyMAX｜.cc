#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
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

int main() {
  fastio;
  int n, q, v, u;
  cin >> n >> q;
  vector<int> a(n), r = {0};
  for (auto& i : a) cin >> i;
  for (int i = 0; i < n - 1; ++i) r.pb(abs(a[i + 1] - a[i]) + r.back());
  while (q--) {
    cin >> u >> v;
    cout << r[v - 1] - r[u - 1] << "\n";
  }
}