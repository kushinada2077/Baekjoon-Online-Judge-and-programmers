#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

int bfs(vector<int>& predf, int a, int b) {
  queue<int> q;
  vector<int> dist(1005, -1);
  if (a + 1 < 1000) {
    q.push(a + 1);
    dist[a + 1] = 1;
  }
  if (a - 1 > 0) {
    q.push(a - 1);
    dist[a - 1] = 1;
  }
  for (auto& pre : predf) {
    q.push(pre);
    dist[pre] = 1;
  }

  while (!q.empty()) {
    auto cur = q.front();
    if (cur == b) return dist[cur];
    q.pop();
    for (int i = -1; i < 2; i += 2) {
      int nxt = cur + i;
      if (nxt < 1 || nxt >= 1000 || dist[nxt] != -1) continue;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
    }
  }
}
int main() {
  fastio;
  int a, b, n;
  cin >> a >> b >> n;
  vector<int> predf(n);
  for (auto& i : predf) cin >> i;
  cout << bfs(predf, a, b) << "\n";
}