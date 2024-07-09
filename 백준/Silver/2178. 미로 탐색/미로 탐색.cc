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
using namespace std;

int n, m;
bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }
void bfs(vector<string>& a, vector<vector<int>>& dist, int r, int c) {
  queue<pair<int, int>> q;
  q.push({r, c});
  dist[r][c] = 0;

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + "2101"[dir] - '1';
      int ny = y + "1210"[dir] - '1';
      if (OOB(nx, ny) || dist[nx][ny] != -1 || a[nx][ny] == '0') continue;
      q.push({nx, ny});
      dist[nx][ny] = dist[x][y] + 1;
    }
  }
}
int main() {
  fastio;
  cin >> n >> m;
  vector<string> a(n);
  vector<vector<int>> dist(n, vector<int>(m, -1));
  for (auto& i : a) cin >> i;
  bfs(a, dist, 0, 0);
  cout << dist[n - 1][m - 1] + 1 << "\n";
}