#include <algorithm>
#include <iostream>
#include <queue>
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

const int MX = 32005;
int indg[MX];
vector<int> adj[MX];
int main() {
  fastio;
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    adj[a].pb(b);
    indg[b]++;
  }

  priority_queue<int, vector<int>, greater<int>> q;

  for (int i = 1; i <= n; ++i) {
    if (!indg[i]) q.push(i);
  }

  for (int i = 0; i < n; ++i) {
    int cur = q.top();
    q.pop();
    for (auto& nxt : adj[cur]) {
      if (--indg[nxt] == 0) q.push(nxt);
    }
    cout << cur << " ";
  }
}