#define PAIR pair<int, int>
#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[101][101], N, M, x;
string board[101];

void djikstra() {
  priority_queue<TUPLE, vector<TUPLE>, greater<TUPLE>> pq;
  for (int i = 0; i < N; i++) {
    fill(d[i], d[i] + M, INF);
  }
  pq.push({0, 0, 0});
  d[0][0] = 0;

  while (!pq.empty()) {
    auto [dis, x, y] = pq.top();
    pq.pop();
    if (dis != d[x][y]) continue;
    for (int i = 0; i < 4; i++) {
      int nx = x + "2101"[i] - '1';
      int ny = y + "1012"[i] - '1';
      if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
      if (dis + (board[nx][ny] - '0') >= d[nx][ny]) continue;
      d[nx][ny] = dis + (board[nx][ny] - '0');
      pq.push({d[nx][ny], nx, ny});
    }
  }

  if (d[N - 1][M - 1] == INF) d[N - 1][M - 1] = 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M >> N;
  for (int i = 0; i < N; i++) {
    cin >> board[i];
  }

  djikstra();
  cout << d[N - 1][M - 1];
}