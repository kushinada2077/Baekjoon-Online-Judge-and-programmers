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
  int n, q, x, a, b;
  cin >> n >> q;
  vector<vector<int>> r(3, vector<int>(1, 0));
  for (int i = 0; i < n; ++i) {
    cin >> x;
    x--;
    for (int j = 0; j < 3; ++j) {
      r[j].pb(r[j].back());
      if (x == j) r[j].back()++;
    }
  }
  while (q--) {
    cin >> a >> b;
    for (int j = 0; j < 3; ++j) cout << r[j][b] - r[j][a - 1] << " ";
    cout << "\n";
  }
}