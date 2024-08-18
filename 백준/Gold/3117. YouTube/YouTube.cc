#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

const int MX = 100005;
const int MX_D = 30;

// nxt[i][j] = i번째 동영상의 2^j분 후 다음번째 동영상
int st[MX], nxt[MX][MX_D], clip[MX];
int main() {
  fastio;
  int n, k, m;
  cin >> n >> k >> m;
  m--;
  for (int i = 1; i <= n; ++i) cin >> st[i];
  for (int i = 1; i <= k; ++i) cin >> clip[i];
  for (int i = 1; i <= k; ++i) nxt[i][0] = clip[i];

  for (int j = 1; j < MX_D; ++j) {
    for (int i = 1; i <= k; ++i) {
      nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
    }
  }

  for (int i = 1; i <= n; ++i) {
    int x = st[i];
    for (int j = MX_D - 1; j >= 0; --j) {
      if (m & (1 << j)) {
        x = nxt[x][j];
      }
    }
    cout << x << " ";
  }
}