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
#define X first
#define Y second
using namespace std;

int n, m, k;
vector<vector<bool>> vis(101, vector<bool>(101, false));
bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }
int bfs(vector<vector<int>>& board, int st_x, int st_y) {
  int ret = 0;
  queue<pair<int, int>> q;
  q.push({st_x, st_y});
  vis[st_x][st_y] = true;

  while (!q.empty()) {
    ret++;
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + "2101"[dir] - '1';
      int ny = y + "1210"[dir] - '1';
      if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny]) continue;
      q.push({nx, ny});
      vis[nx][ny] = true;
    }
  }
  return ret;
}
int main() {
  fastio;
  cin >> n >> m >> k;
  int x1, x2, y1, y2;
  vector<vector<int>> board(n, vector<int>(m, 0));
  vector<int> ans;
  while (k--) {
    cin >> y1 >> x1 >> y2 >> x2;
    for (int i = x1; i < x2; ++i) {
      for (int j = y1; j < y2; ++j) {
        board[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (vis[i][j] || board[i][j]) continue;
      ans.pb(bfs(board, i, j));
    }
  }
  sort(all(ans));
  cout << si(ans) << "\n";
  for (auto& i : ans) cout << i << " ";
}