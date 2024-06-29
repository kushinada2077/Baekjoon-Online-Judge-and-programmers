#define ll long long
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m, ans = 0x3f3f3f3f;
string board[50];
bool f(char c) { return c == 'W'; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> board[i];
  for (int i = 0; i < n - 7; ++i) {
    for (int j = 0; j < m - 7; ++j) {
      int cnt = 0;
      for (int x = i; x < i + 8; ++x) {
        for (int y = j; y < j + 8; ++y) {
          cnt += f(board[x][y]) == ((x + y) & 1);
        }
      }
      ans = min(min(ans, cnt), 64 - cnt);
    }
  }
  cout << ans;
}