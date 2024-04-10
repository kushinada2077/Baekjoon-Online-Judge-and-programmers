#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, a, b, c;
int d[101][101], nxt[101][101];

void loop(void (*func)(int i, int j)) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      func(i, j);
    }
  }
}

void path_tracing(int u, int v) {
  if (u == v || d[u][v] == INF) {
    cout << "0\n";
    return;
  }

  vector<int> path;

  while (u != v) {
    path.push_back(u);
    u = nxt[u][v];
  }
  path.push_back(v);

  cout << path.size() << " ";
  for (auto n : path) cout << n << " ";
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fill(d[i], d[i] + n + 1, INF);
    d[i][i] = 0;
  }

  while (m--) {
    cin >> a >> b >> c;
    if (d[a][b] <= c) continue;
    d[a][b] = c;
    nxt[a][b] = b;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (d[i][j] <= d[i][k] + d[k][j]) continue;
        d[i][j] = d[i][k] + d[k][j];
        nxt[i][j] = nxt[i][k];
      }
    }
  }

  loop([](int i, int j) {
    if (d[i][j] == INF)
      cout << "0 ";
    else
      cout << d[i][j] << " ";
    if (j == n) cout << "\n";
  });
  loop(path_tracing);
}