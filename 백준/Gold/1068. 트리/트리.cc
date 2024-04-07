#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, V, T, ans, root;
vector<int> adj[51];
int p[51];
void dfs(int cur) {
  if (T == cur) return;
  if (adj[cur].size() == 0 || (adj[cur].size() == 1 && adj[cur][0] == T)) ans++;
  for (auto nxt : adj[cur]) {
    dfs(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(p, p + 51, -1);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> V;
    p[i] = V;
    if (V != -1) {
      adj[V].push_back(i);
    } else {
      root = i;
    }
  }
  cin >> T;

  dfs(root);

  cout << ans;
}