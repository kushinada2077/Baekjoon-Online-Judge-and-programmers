#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

int t, n, x, y, tx, ty;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int main() {
  fastio;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> x >> y >> tx >> ty;
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(n, -1));
    q.push({x, y});
    dist[x][y] = 0;
    while (!q.empty()) {
      auto& [x, y] = q.front();
      q.pop();
      for (int dir = 0; dir < 8; ++dir) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (dist[nx][ny] != -1) continue;
        q.push({nx, ny});
        dist[nx][ny] = dist[x][y] + 1;
      }
    }

    cout << dist[tx][ty] << "\n";
  }
}