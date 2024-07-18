
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

int n, b, c;
int bfs(vector<int>& a, int from, int to) {
  queue<int> q;
  int nxt;
  q.push(from);
  vector<int> dist(n, -1);
  dist[from] = 0;
  while (!q.empty()) {
    auto cur = q.front();
    if (cur == to) return dist[cur];
    int jump = a[cur];
    q.pop();
    for (int i = 1; (nxt = cur + i * jump) < n; ++i) {
      if (dist[nxt] != -1) continue;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
    }
    for (int i = 1; (nxt = cur - i * jump) >= 0; ++i) {
      if (dist[nxt] != -1) continue;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
    }
  }
  return dist[to];
}
int main() {
  fastio;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  cin >> b >> c;
  cout << bfs(a, b - 1, c - 1) << "\n";
}