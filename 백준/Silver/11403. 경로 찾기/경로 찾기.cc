#include <algorithm>
#include <climits>
#include <iostream>
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

int n;
bool adj[105][105], ans[105][105];

void dfs(int cur, int st) {
  for (int nxt = 0; nxt < n; ++nxt) {
    if (cur == nxt || !adj[cur][nxt] || ans[st][nxt]) continue;
    ans[st][nxt] = 1;
    dfs(nxt, st);
  }
}
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> adj[i][j];
  }

  for (int i = 0; i < n; ++i) {
    dfs(i, i);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << ans[i][j] << " ";
    cout << "\n";
  }
}