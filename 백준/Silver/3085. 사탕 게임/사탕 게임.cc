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

string board[51];

int main() {
  fastio;
  int n, ans = 1;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> board[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int dir = 0; dir < 4; ++dir) {
        int x = i + "2101"[dir] - '1', y = j + "1210"[dir] - '1';
        if (x < 0 || x >= n || y < 0 || y >= n) continue;
        swap(board[i][j], board[x][y]);
        for (int r = 0; r < n; ++r) {
          int cnt = 1, cur = board[r][0];
          for (int c = 1; c < n; ++c) {
            if (cur != board[r][c]) {
              ans = max(ans, cnt);
              cnt = 0;
              cur = board[r][c];
            }
            cnt++;
          }
          ans = max(ans, cnt);
        }
        for (int c = 0; c < n; ++c) {
          int cnt = 1, cur = board[0][c];
          for (int r = 1; r < n; ++r) {
            if (cur != board[r][c]) {
              ans = max(ans, cnt);
              cnt = 0;
              cur = board[r][c];
            }
            cnt++;
          }
          ans = max(ans, cnt);
        }
        swap(board[i][j], board[x][y]);
      }
    }
  }

  cout << ans << "\n";
}