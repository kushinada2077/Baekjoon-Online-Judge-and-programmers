#include <algorithm>
#include <iostream>
#include <queue>
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

vector<string> maze(1005);
vector<vector<vector<int>>> dist(1005, vector<vector<int>>(1005, vector<int>(2, -1)));
int r, c, jx, jy;
int bfs(vector<pair<int, int>>& fire) {
  queue<tuple<int, int, int>> q;
  for (auto& [fx, fy] : fire) {
    q.push({fx, fy, 1});
    dist[fx][fy][1] = 0;
  }
  q.push({jx, jy, 0});
  dist[jx][jy][0] = 0;
  while (!q.empty()) {
    auto [x, y, state] = q.front();
    if (state == 0 && (x == 0 || x == r - 1 || y == 0 || y == c - 1)) return dist[x][y][0] + 1;
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + "2101"[dir] - '1';
      int ny = y + "1210"[dir] - '1';
      if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if (dist[nx][ny][state] != -1 || maze[nx][ny] == '#') continue;
      if (state == 0 && dist[nx][ny][1] != -1) continue;
      q.push({nx, ny, state});
      dist[nx][ny][state] = dist[x][y][state] + 1;
    }
  }
  return -1;
}
int main() {
  fastio;
  cin >> r >> c;
  vector<pair<int, int>> fire;
  for (int i = 0; i < r; ++i) {
    cin >> maze[i];
    for (int j = 0; j < c; ++j) {
      if (maze[i][j] == 'F') {
        fire.pb({i, j});
      } else if (maze[i][j] == 'J') {
        jx = i;
        jy = j;
      }
    }
  }

  int res = bfs(fire);
  if (res == -1) cout << "IMPOSSIBLE\n";
  else cout << res << "\n";
}