#define ll long long
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m, ans = 0x3f3f3f3f;
string board[50];
char color[2] = {'B', 'W'};
int count(int r, int c) {
  int ret = 0x3f3f3f3f;
  for (int t = 0; t < 2; ++t) {
    int cnt = 0;
    for (int i = r; i < r + 8; ++i) {
      int idx = (i + t) & 1 & 1;
      for (int j = c; j < c + 8; ++j) {
        if (board[i][j] != color[idx]) cnt++;
        idx = (idx + 1) % 2;
      }
    }
    ret = min(ret, cnt);
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> board[i];
  for (int i = 0; i < n - 7; ++i) {
    for (int j = 0; j < m - 7; ++j) {
      ans = min(ans, count(i, j));
    }
  }
  cout << ans;
}