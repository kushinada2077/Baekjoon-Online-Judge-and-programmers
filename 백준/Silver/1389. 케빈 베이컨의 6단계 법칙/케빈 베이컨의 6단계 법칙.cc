#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, v1, v2;
vector<int> adj[101];
vector<int> ans{0};

int bfs(int V) {
  int dis[N + 1];
  queue<int> q;
  fill(dis + 1, dis + 1 + N, -1);
  q.push(V);
  dis[V] = 0;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (auto nxt : adj[cur]) {
      if (dis[nxt] != -1) continue;
      q.push(nxt);
      dis[nxt] = dis[cur] + 1;
    }
  }

  int sum = 0;
  for (int i = 1; i < N + 1; i++) {
    if (i != V) sum += dis[i];
  }

  return sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  while (M--) {
    cin >> v1 >> v2;
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }

  for (int i = 1; i < N + 1; i++) {
    ans.push_back(bfs(i));
  }

  auto ret = min_element(next(ans.begin()), ans.end()) - ans.begin();
  cout << ret;
}