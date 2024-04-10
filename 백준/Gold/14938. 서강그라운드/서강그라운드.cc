#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, a, b, c, r, ans = -1;
int d[101][101], item[101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    item[i] = a;
  }
  for (int i = 1; i <= n; i++) {
    fill(d[i], d[i] + n + 1, INF);
    d[i][i] = 0;
  }
  while (r--) {
    cin >> a >> b >> c;
    d[a][b] = c;
    d[b][a] = c;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (d[i][j] <= d[i][k] + d[k][j]) continue;
        d[i][j] = d[i][k] + d[k][j];
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 1; j <= n; j++) {
      if (d[i][j] <= m) {
        sum += item[j];
      }
    }

    if (sum > ans) ans = sum;
  }

  cout << ans;
}