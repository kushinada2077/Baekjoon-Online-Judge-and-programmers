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

string board[11];
int bfs(int st_x, int st_y) {
  queue<pair<int, int>> q;
  vector<vector<int>> dist(10, vector<int>(10, -1));
  q.push({st_x, st_y});
  dist[st_x][st_y] = 0;

  while (!q.empty()) {
    auto [x, y] = q.front();
    if (board[x][y] == 'L') return dist[x][y] - 1;
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + "2101"[dir] - '1';
      int ny = y + "1210"[dir] - '1';
      if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10 || dist[nx][ny] != -1 || board[nx][ny] == 'R') continue;
      q.push({nx, ny});
      dist[nx][ny] = dist[x][y] + 1;
    }
  }
}
int main() {
  fastio;
  int x, y;
  for (int i = 0; i < 10; ++i) {
    cin >> board[i];
    for (int j = 0; j < 10; ++j) {
      if (board[i][j] == 'B') {
        x = i;
        y = j;
      }
    }
  }
  cout << bfs(x, y) << "\n";
}