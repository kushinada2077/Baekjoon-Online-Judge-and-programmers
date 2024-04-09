#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, a, b, c, d[101][101];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      d[i][j] = INF;
    }
  }
  while (m--) {
    cin >> a >> b >> c;
    d[a][b] = min(d[a][b], c);
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (d[i][j] == INF) d[i][j] = 0;
      cout << d[i][j] << " ";
    }
    cout << "\n";
  }
}