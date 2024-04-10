#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, K, x, d[11][11];
bool chk[11];

void tracking(int k, int cur, int sum) {
  if (k == N) {
    if (sum < x) x = sum;
    return;
  }

  for (int i = 0; i < N; i++) {
    if (chk[i]) continue;
    chk[i] = 1;
    tracking(k + 1, i, sum + d[cur][i]);
    chk[i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    fill(d[i], d[i] + N + 1, INF);
    for (int j = 0; j < N; j++) {
      cin >> x;
      d[i][j] = x;
    }
  }

  for (int k = 0; k <= N; k++) {
    for (int i = 0; i <= N; i++) {
      for (int j = 0; j <= N; j++) {
        if (d[i][j] <= d[i][k] + d[k][j]) continue;
        d[i][j] = d[i][k] + d[k][j];
      }
    }
  }

  x = 0x3f3f3f3f;
  tracking(0, K, 0);
  cout << x;
}