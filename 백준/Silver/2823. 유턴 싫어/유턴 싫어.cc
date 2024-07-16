#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

int r, c;
string a[11];
bool OOB(int a, int b) { return a < 0 || a >= r || b < 0 || b >= c; }
int main() {
  fastio;
  cin >> r >> c;
  for (int i = 0; i < r; ++i) cin >> a[i];
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (a[i][j] == 'X') continue;
      int cnt = 0;
      for (int dir = 0; dir < 4; ++dir) {
        int nx = "2101"[dir] - '1' + i;
        int ny = "1012"[dir] - '1' + j;
        if (OOB(nx, ny) || a[nx][ny] == 'X') continue;
        cnt++;
      }
      if (cnt < 2) {
        cout << "1\n";
        return 0;
      }
    }
  }
  cout << "0\n";
}