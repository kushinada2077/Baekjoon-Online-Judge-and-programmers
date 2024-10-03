#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
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

const int MX = 1001;
int n, val;
int e_num[MX][MX], degree[MX];
vector<int> adj[MX];
bool vis[MX];

void eulerian(int cur) {
  while (si(adj[cur])) {
    int nxt = adj[cur].back();
    if (e_num[cur][nxt]) {
      e_num[cur][nxt]--;
      e_num[nxt][cur]--;
      eulerian(nxt);
    } else adj[cur].pop_back();
  }

  cout << cur + 1 << " ";
}
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> val;
      if (val > 0) {
        adj[i].pb(j);
        e_num[i][j] = val;
        degree[i] += val;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (degree[i] % 2) {
      cout << "-1\n";
      return 0;
    }
  }

  eulerian(0);
}