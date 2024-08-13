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

int r, c, k, ans;
string board[6];
vector<vector<bool>> vis(6, vector<bool>(6, false));
void dfs(int n, int x, int y) {
  if (n == k - 1) {
    if (x == 0 && y == c - 1) ans++;
    return;
  }
  for (int dir = 0; dir < 4; ++dir) {
    int nx = x + "2101"[dir] - '1';
    int ny = y + "1210"[dir] - '1';
    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
    if (vis[nx][ny] || board[nx][ny] == 'T') continue;
    vis[nx][ny] = true;
    dfs(n + 1, nx, ny);
    vis[nx][ny] = false;
  }
}
int main() {
  fastio;
  cin >> r >> c >> k;
  for (int i = 0; i < r; ++i) cin >> board[i];
  vis[r - 1][0] = true;
  dfs(0, r - 1, 0);
  cout << ans << "\n";
}