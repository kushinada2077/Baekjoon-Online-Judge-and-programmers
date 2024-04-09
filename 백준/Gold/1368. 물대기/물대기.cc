#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int N, W[301], P[301][301], x, cnt, ans;
bool chk[301];
pair<int, int> mn = {0, 100001};
priority_queue<TUPLE, vector<TUPLE>, greater<TUPLE>> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> x;
    if (mn.second > x) {
      mn.first = i;
      mn.second = x;
    }
    W[i] = x;
  }
  for (int i = 1; i <= N; i++) {
    if (mn.first == i) continue;
    pq.push({W[i], -1, i});
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> x;
      P[i][j] = x;
    }
  }

  chk[mn.first] = 1;
  cnt++;
  ans += mn.second;
  for (int i = 1; i <= N; i++) {
    if (mn.first == i) continue;
    pq.push({P[mn.first][i], mn.first, i});
  }

  while (cnt < N) {
    auto [cost, a, b] = pq.top();
    pq.pop();
    if (chk[b]) continue;
    ans += cost;
    chk[b] = 1;
    cnt++;
    for (int i = 1; i <= N; i++) {
      if (chk[i]) continue;
      pq.push({P[b][i], b, i});
    }
  }

  cout << ans;
}