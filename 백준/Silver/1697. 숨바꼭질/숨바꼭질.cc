#include <algorithm>
#include <iostream>
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

int f(int cur, int dir) {
  if (dir == 0) return cur - 1;
  if (dir == 1) return cur + 1;
  return 2 * cur;
}
int main() {
  fastio;
  int n, k;
  cin >> n >> k;
  queue<int> q;
  vector<int> dist(100005, -1);
  q.push(n);
  dist[n] = 0;
  while (!q.empty()) {
    int cur = q.front();
    if (cur == k) {
      cout << dist[cur] << "\n";
      return 0;
    }
    q.pop();
    for (int dir = 0; dir < 3; ++dir) {
      int nxt = f(cur, dir);
      if (nxt < 0 || nxt > 100000) continue;
      if (dist[nxt] != -1) continue;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
    }
  }
}