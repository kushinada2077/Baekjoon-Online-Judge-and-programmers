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

int n, m, x1, x2, _y1, y2;
int main() {
  fastio;
  cin >> n >> m;
  vector<vector<int>> board(n + 1, vector<int>(n + 1, 0)), p_sum(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; ++i) {
    int tot = 0;
    for (int j = 1; j <= n; ++j) {
      cin >> board[i][j];
      tot += board[i][j];
      p_sum[i][j] = tot;
    }
  }
  while (m--) {
    cin >> x1 >> _y1 >> x2 >> y2;
    int tot = 0;
    for (int i = x1; i <= x2; ++i) tot += p_sum[i][y2] - p_sum[i][_y1 - 1];
    cout << tot << "\n";
  }
}