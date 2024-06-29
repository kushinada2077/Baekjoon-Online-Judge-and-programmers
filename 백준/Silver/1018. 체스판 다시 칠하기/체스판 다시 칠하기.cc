#define ll long long
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m, ans = 0x3f3f3f3f;
string board[50];
bool f(char c) { return c == 'W'; }
int count(int r, int c) {
  int cnt = 0;
  for (int i = r; i < r + 8; ++i) {
    for (int j = c; j < c + 8; ++j) {
      if (f(board[i][j]) != ((i + j) & 1)) cnt++;
    }
  }
  return cnt > 32 ? 64 - cnt : cnt;
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