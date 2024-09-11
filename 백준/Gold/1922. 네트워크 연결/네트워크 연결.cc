#include <algorithm>
#include <iostream>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

vector<tuple<int, int, int>> edge;
vector<int> p(1005, -1);
int find(int v) {
  if (p[v] < 0) return v;
  p[v] = find(p[v]);
  return p[v];
}

bool merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return true;
  if (p[a] < p[b]) {
    p[a] += p[b];
    p[b] = a;
  } else {
    p[b] += p[a];
    p[a] = b;
  }

  return false;
}

int main() {
  fastio;
  int n, m, a, b, c;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    if (a == b) continue;
    edge.pb({c, a, b});
  }

  sort(all(edge));
  int cnt = 0, ans = 0;
  for (int i = 0; i < si(edge) && cnt < n; ++i) {
    auto [c, v, u] = edge[i];
    if (merge(v, u)) continue;
    cnt++;
    ans += c;
  }
  cout << ans << "\n";
}