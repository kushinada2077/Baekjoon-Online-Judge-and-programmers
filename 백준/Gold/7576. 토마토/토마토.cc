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

int m, n;
bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }
int bfs(vector<vector<int>>& box, vector<pair<int, int>>& st) {
  queue<pair<int, int>> q;
  vector<vector<int>> dist(n, vector<int>(m, -1));
  int ret = 0;
  for (auto [x, y] : st) {
    q.push({x, y});
    dist[x][y] = 0;
  }

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + "2101"[dir] - '1';
      int ny = y + "1210"[dir] - '1';
      if (OOB(nx, ny) || box[nx][ny] != 0 || dist[nx][ny] != -1) continue;
      q.push({nx, ny});
      box[nx][ny] = 1;
      dist[nx][ny] = dist[x][y] + 1;
      if (ret < dist[nx][ny]) ret = dist[nx][ny];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (box[i][j] == 0) return -1;
    }
  }
  return ret;
}
int main() {
  fastio;
  cin >> m >> n;
  vector<vector<int>> box(n, vector<int>(m));
  vector<pair<int, int>> st;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> box[i][j];
      if (box[i][j] == 1) st.pb({i, j});
    }
  }
  cout << bfs(box, st) << "\n";
}