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

char c;
int cnt = 9, cnt2 = 0;
int indg[10], indg2[10], ans[10], ans2[10];
vector<int> adj[10], adj2[10];
int main() {
  fastio;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c;
    if (c == '<') {
      indg[i]++;
      adj[i + 1].pb(i);
      indg2[i + 1]++;
      adj2[i].pb(i + 1);
    } else {
      indg[i + 1]++;
      adj[i].pb(i + 1);
      indg2[i]++;
      adj2[i + 1].pb(i);
    }
  }

  priority_queue<int, vector<int>, greater<int>> q, q2;
  for (int i = 0; i <= n; ++i) {
    if (indg[i] == 0) {
      q.push(i);
    }
    if (indg2[i] == 0) {
      q2.push(i);
    }
  }

  while (!q.empty()) {
    int cur = q.top();
    q.pop();
    ans[cur] = cnt--;
    for (auto& nxt : adj[cur]) {
      if (--indg[nxt] == 0) q.push(nxt);
    }
  }

  while (!q2.empty()) {
    int cur = q2.top();
    q2.pop();
    ans2[cur] = cnt2++;
    for (auto& nxt : adj2[cur]) {
      if (--indg2[nxt] == 0) q2.push(nxt);
    }
  }

  for (int i = 0; i <= n; ++i) cout << ans[i];
  cout << "\n";
  for (int i = 0; i <= n; ++i) cout << ans2[i];
}