#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, K, a, b, c, t[201], d[201][201], ans;
vector<int> f;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    fill(d[i], d[i] + N + 1, INF);
    d[i][i] = 0;
  }
  while (M--) {
    cin >> a >> b >> c;
    d[a][b] = c;
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (d[i][j] <= d[i][k] + d[k][j]) continue;
        d[i][j] = d[i][k] + d[k][j];
      }
    }
  }

  cin >> K;
  while (K--) {
    cin >> M;
    f.push_back(M);
  }

  int mn = INF;
  for (int i = 1; i <= N; i++) {
    int mx = -1;
    for (auto u : f) {
      if (mx >= d[u][i] + d[i][u]) continue;
      mx = d[u][i] + d[i][u];
    }
    t[i] = mx;
    if (mx < mn) mn = mx;
  }

  for (int i = 1; i <= N; i++) {
    if (mn == t[i]) cout << i << " ";
  }
}