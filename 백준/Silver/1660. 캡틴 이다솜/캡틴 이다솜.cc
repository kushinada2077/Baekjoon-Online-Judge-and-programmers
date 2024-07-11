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

int n;
vector<bool> dist(3e5 + 5, 0);
vector<int> a;
int bfs() {
  queue<int> q;
  vector<int> dist(300005, 0);
  for (int i = 0; i < si(a) && a[i] <= n; ++i) {
    q.push(a[i]);
    dist[a[i]] = 1;
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < si(a); ++i) {
      int nxt = cur + a[i];
      if (nxt > n || dist[nxt]) continue;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
    }
  }
  return dist[n];
}
int main() {
  fastio;
  int d = 1, cur = 0, tot = 0;
  cin >> n;
  while (tot <= 3e5) {
    cur += d++;
    tot += cur;
    a.pb(tot);
  }
  cout << bfs() << "\n";
}