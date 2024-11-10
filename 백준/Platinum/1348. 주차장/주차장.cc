#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define L_PATH "input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

const int MX = 305;
int n, m, dist[101][60][60], A[MX], B[MX];
bool vis[MX];
string board[60];
vector<P> car, parking;
vector<int> adj[MX];

void init() {
  for (int i = 0; i < MX; ++i) {
    A[i] = B[i] = -1;
    vis[i] = 0;
    adj[i].clear();
  }
}
bool dfs(int a) {
  vis[a] = 1;
  for (int b : adj[a]) {
    if (B[b] == -1 || !vis[B[b]] && dfs(B[b])) {
      A[a] = b;
      B[b] = a;
      return 1;
    }
  }

  return 0;
}
int main() {
  fastio;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> board[i];
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == 'C') car.pb(P(i, j));
      if (board[i][j] == 'P') parking.pb(P(i, j));
    }
  }

  for (int i = 0; i < si(car); ++i) {
    for (int j = 0; j < n; ++j) fill(dist[i][j], dist[i][j] + 60, -1);
    queue<P> q;
    auto [sy, sx] = car[i];
    q.push(P(sy, sx));
    dist[i][sy][sx] = 0;

    while (!q.empty()) {
      auto [y, x] = q.front();
      q.pop();
      for (int dir = 0; dir < 4; ++dir) {
        int nx = x + "2101"[dir] - '1', ny = y + "1210"[dir] - '1';
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if (dist[i][ny][nx] != -1 || board[ny][nx] == 'X') continue;
        q.push(P(ny, nx));
        dist[i][ny][nx] = dist[i][y][x] + 1;
      }
    }
  }

  int lo = -1, hi = 10000;
  while (lo + 1 < hi) {
    init();
    int mid = (lo + hi) / 2;
    for (int i = 0; i < si(car); ++i) {
      auto [sy, sx] = car[i];
      for (int j = 0; j < si(parking); ++j) {
        auto [ey, ex] = parking[j];
        if (dist[i][ey][ex] == -1 || dist[i][ey][ex] > mid) continue;
        adj[2 * i].pb(2 * j + 1);
      }
    }

    int cnt = 0;
    for (int i = 0; i < si(car); ++i) {
      fill(vis, vis + MX, 0);
      if (dfs(2 * i)) cnt++;
    }

    if (cnt >= si(car)) hi = mid;
    else lo = mid;
  }

  if (hi == 10000) hi = -1;
  cout << hi << "\n";
}