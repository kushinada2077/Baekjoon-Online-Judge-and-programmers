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

const int MX_COL = 2002, MX = 500 * 500 * 3;
char board[MX_COL][MX_COL];
string s;
int TC, h, v, cnt = 1, chk[MX_COL][MX_COL], B[MX];
bool vis[MX];
vector<int> adj[MX];

void init() {
  for (int i = 0; i < MX; ++i) {
    adj[i].clear();
    B[i] = -1;
    cnt = 1;
  }
  for (int i = 0; i < MX_COL; ++i) {
    for (int j = 0; j < MX_COL; ++j) board[i][j] = chk[i][j] = 0;
  }
}
bool dfs(int a) {
  vis[a] = 1;
  for (int b : adj[a]) {
    if (B[b] == -1 || !vis[B[b]] && dfs(B[b])) {
      B[b] = a;
      return 1;
    }
  }

  return 0;
}
int main() {
  fastio;
  cin >> TC;

  while (TC--) {
    init();
    cin >> h >> v;
    for (int x, y, i = 0; i < h; ++i) {
      cin >> x >> y >> s;
      for (int i = x; i < x + si(s); ++i) {
        board[y][i] = s[i - x];
        chk[y][i] = cnt;
      }
      cnt++;
    }

    int num = cnt;
    cnt = 1;
    for (int x, y, i = 0; i < v; ++i) {
      cin >> x >> y >> s;
      for (int i = y; i < y + si(s); ++i) {
        if (board[i][x] != 0 && board[i][x] != s[i - y]) {
          adj[2 * chk[i][x]].pb(2 * cnt + 1);
        }
      }
      cnt++;
    }

    int maxFlow = 0;
    for (int i = 1; i < num; ++i) {
      fill(vis, vis + 3 * cnt, 0);
      if (dfs(2 * i)) maxFlow++;
    }

    cout << h + v - maxFlow << "\n";
  }
}