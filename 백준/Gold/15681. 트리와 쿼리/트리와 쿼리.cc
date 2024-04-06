#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, R, Q, U, V;
vector<int> adj[100001];
int p[100001];
int cnt[100001];

void dfs(int cur) {
  for (auto nxt : adj[cur]) {
    if (p[cur] == nxt) continue;
    p[nxt] = cur;
    dfs(nxt);
    cnt[cur] += cnt[nxt];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> R >> Q;
  fill(cnt, cnt + N + 1, 1);
  int M = N - 1;
  while (M--) {
    cin >> U >> V;
    adj[U].push_back(V);
    adj[V].push_back(U);
  }

  dfs(R);

  while (Q--) {
    cin >> U;
    cout << cnt[U] << "\n";
  }
}