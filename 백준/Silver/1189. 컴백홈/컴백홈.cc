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

int r, c, k, ans;
string board[10];
vector<vector<bool>> vis(10, vector<bool>(10, false));

void f(int x, int y, int cnt) {
  if (cnt > k) return;
  if (x == 0 && y == c - 1 && cnt == k) {
    ans++;
    return;
  }
  for (int dir = 0; dir < 4; ++dir) {
    int nx = x + "2101"[dir] - '1';
    int ny = y + "1210"[dir] - '1';
    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
    if (board[nx][ny] == 'T' || vis[nx][ny]) continue;
    vis[nx][ny] = true;
    f(nx, ny, cnt + 1);
    vis[nx][ny] = false;
  }
}
int main() {
  fastio;
  cin >> r >> c >> k;
  for (int i = 0; i < r; ++i) cin >> board[i];
  vis[r - 1][0] = true;
  f(r - 1, 0, 1);
  cout << ans << "\n";
}