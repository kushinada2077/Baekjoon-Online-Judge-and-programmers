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
  int n, m, a, b, x;
  cin >> n >> m;
  vector<int> r = {0};
  for (int i = 0; i < n; ++i) {
    cin >> x;
    r.pb(r.back() + x);
  }

  while (m--) {
    cin >> a >> b;
    cout << r[b] - r[a - 1] << "\n";
  }
}