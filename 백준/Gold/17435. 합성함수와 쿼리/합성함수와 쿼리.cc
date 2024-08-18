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

int m, q, n, x;
int nxt[500005][19];
int main() {
  fastio;
  cin >> m;
  for (int i = 1; i <= m; ++i) cin >> nxt[i][0];

  for (int j = 1; j < 19; ++j) {
    for (int i = 1; i <= m; ++i) nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
  }

  cin >> q;
  while (q--) {
    cin >> n >> x;
    for (int i = 18; i >= 0; --i) {
      if (n >= 1 << i) {
        n -= 1 << i;
        x = nxt[x][i];
      }
    }
    cout << x << "\n";
  }
}