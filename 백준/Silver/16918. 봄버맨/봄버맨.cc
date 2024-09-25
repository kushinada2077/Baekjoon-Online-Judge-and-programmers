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

int board[201][201];
int main() {
  fastio;
  int r, c, n;
  char x;
  cin >> r >> c >> n;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> x;
      if (x == '.') board[i][j] = 0;
      else board[i][j] = 2;
    }
  }
  n--;

  for (int i = 0; i < n; ++i) {
    if ((i & 1) == 0) {
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          if (board[i][j] == 0) board[i][j] = 3;
          else board[i][j]--;
        }
      }
    } else {
      vector<pair<int, int>> tmp;
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          if (board[i][j] == 1) tmp.pb({i, j});
          if (board[i][j]) board[i][j]--;
        }
      }
      for (auto [x, y] : tmp) {
        for (int dir = 0; dir < 4; ++dir) {
          int nx = x + "2101"[dir] - '1', ny = y + "1210"[dir] - '1';
          if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
          board[nx][ny] = 0;
        }
      }
    }
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (board[i][j]) cout << "O";
      else cout << ".";
    }
    cout << "\n";
  }
}