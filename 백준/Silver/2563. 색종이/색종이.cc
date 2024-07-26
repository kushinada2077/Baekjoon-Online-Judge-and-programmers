#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

bool no_dup(int al, int ar, int bl, int br) { return ar <= bl || br <= al; }
int main() {
  fastio;
  int n, x, y, ans = 0;
  vector<vector<bool>> paper(100, vector<bool>(100));
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    for (int i = y; y < 100 && i < y + 10; ++i) {
      for (int j = x; j < 100 && j < x + 10; ++j) paper[i][j] = true;
    }
  }
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) ans += paper[i][j];
  }
  cout << ans << "\n";
}