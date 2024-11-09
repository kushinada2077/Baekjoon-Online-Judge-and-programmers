#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define L_PATH "input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

const int MX = 200;
int n, indg[MX], A[MX], B[MX];
bool vis[MX];
vector<TP> shark;
vector<int> adj[MX];

bool dfs(int a) {
  vis[a] = 1;
  for (int b : adj[a]) {
    if (B[b] == -1 || !vis[B[b]] && dfs(B[b])) {
      A[a] = b;
      B[b] = a;
      return 1;
    }
  }
  return 0;
}
int main() {
  fastio;
  for (int i = 0; i < MX; ++i) A[i] = B[i] = -1;
  cin >> n;
  for (int a, b, c, i = 0; i < n; ++i) {
    cin >> a >> b >> c;
    shark.pb(TP(a, b, c));
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      auto [a1, b1, c1] = shark[i];
      auto [a2, b2, c2] = shark[j];
      if (shark[i] == shark[j] && i < j) {
        adj[3 * i].pb(3 * j + 2);
        adj[3 * i + 1].pb(3 * j + 2);
        indg[j]++;
      }
      if (shark[i] != shark[j] && a1 >= a2 && b1 >= b2 && c1 >= c2) {
        adj[3 * i].pb(3 * j + 2);
        adj[3 * i + 1].pb(3 * j + 2);
        indg[j]++;
      }
    }
  }

  vector<int> order(n);
  for (int i = 0; i < n; ++i) order[i] = i;
  sort(all(order), [&](int a, int b) { return indg[a] > indg[b]; });

  int cnt = 0;
  for (int i : order) {
    int u = 3 * i;
    fill(vis, vis + MX, 0);
    if (dfs(u)) cnt++;
    u++;
    fill(vis, vis + MX, 0);
    if (dfs(u)) cnt++;
  }

  cout << n - cnt << "\n";
}