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

int n, l, r;
int board[55][55];
bool vis[55][55];
bool chk(int x, int y) {
  if (vis[x][y]) return false;
  for (int dir = 0; dir < 4; ++dir) {
    int nx = x + "2101"[dir] - '1';
    int ny = y + "1210"[dir] - '1';
    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
    if (abs(board[nx][ny] - board[x][y]) <= r && abs(board[nx][ny] - board[x][y]) >= l) return true;
  }
  return false;
}

void bfs(int sx, int sy) {
  queue<pair<int, int>> q;
  vector<pair<int, int>> chn;
  int tot = 0;
  q.push({sx, sy});
  vis[sx][sy] = 1;

  while (!q.empty()) {
    auto& [x, y] = q.front();
    q.pop();
    chn.pb({x, y});
    tot += board[x][y];
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + "2101"[dir] - '1';
      int ny = y + "1210"[dir] - '1';
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (abs(board[nx][ny] - board[x][y]) > r || abs(board[nx][ny] - board[x][y]) < l) continue;
      if (vis[nx][ny]) continue;
      q.push({nx, ny});
      vis[nx][ny] = true;
    }
  }
  int nv = tot / si(chn);
  for (auto& [x, y] : chn) board[x][y] = nv;
}
int main() {
  fastio;
  cin >> n >> l >> r;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> board[i][j];
  }
  int ans = 0;

  while (true) {
    bool bre = true;
    for (int i = 0; i <= n; ++i) fill(vis[i], vis[i] + n + 1, false);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (chk(i, j)) {
          if (bre) bre = false;
          bfs(i, j);
        }
      }
    }
    if (bre) break;
    ans++;
  }
  cout << ans << "\n";
}