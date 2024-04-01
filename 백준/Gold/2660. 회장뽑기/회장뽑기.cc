#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, v1, v2;
vector<int> adj[51];
vector<int> ans(51);
vector<int> candi;

int bfs(int v) {
  int dist[51];
  int score = 1;
  fill(dist + 1, dist + 1 + N, -1);
  queue<int> q;

  q.push(v);
  dist[v] = 0;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (auto nxt : adj[cur]) {
      if (dist[nxt] != -1) continue;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
      score = max(score, dist[nxt]);
    }
  }

  return score;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(ans.begin(), ans.end(), 10000);
  cin >> N;
  while (true) {
    cin >> v1 >> v2;
    if (v1 == -1 && v2 == -1) break;
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }

  for (int i = 1; i < N + 1; i++) {
    ans[i] = bfs(i);
  }

  int mn = *min_element(ans.begin(), ans.end());
  int cnt = 0;

  for (int i = 1; i < N + 1; i++) {
    if (ans[i] == mn) {
      cnt++;
      candi.push_back(i);
    }
  }

  cout << mn << " " << cnt << "\n";
  for (auto i : candi) cout << i << " ";
}