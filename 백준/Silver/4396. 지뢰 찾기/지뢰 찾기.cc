#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int n;
string a[11], b[11], ans[11];
bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }
int chk(int x, int y) {
  if (a[x][y] == '*') return -1;
  int ret = 0;
  for (int dir = 0; dir < 8; ++dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (OOB(nx, ny)) continue;
    if (a[nx][ny] == '*') ret++;
  }
  return ret;
}
int main() {
  fastio;
  cin >> n;
  bool f = false;
  for_in(n) cin >> a[i];
  for_in(n) {
    cin >> b[i];
    ans[i] = "";
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (b[i][j] == 'x') {
        int num = chk(i, j);
        if (!f && num == -1) f = true;
        ans[i][j] = num + '0';
      } else {
        ans[i][j] = '.';
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << (f && a[i][j] == '*' ? '*' : ans[i][j]);
    cout << "\n";
  }
}