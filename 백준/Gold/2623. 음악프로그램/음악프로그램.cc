#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, V, O;
int deg[1001];
vector<int> adj[1001];
vector<int> ans;

string phase() {
  queue<int> q;
  for (int i = 1; i <= N; i++) {
    if (deg[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    ans.push_back(cur);
    for (auto nxt : adj[cur]) {
      deg[nxt]--;
      if (deg[nxt] == 0) q.push(nxt);
    }
  }

  if (ans.size() != N)
    return "0";
  else {
    string ret;
    for (auto n : ans) {
      ret += to_string(n) + "\n";
    }

    return ret;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  while (M--) {
    vector<int> tmp;
    cin >> O;
    while (O--) {
      cin >> V;
      tmp.push_back(V);
    }
    for (int i = 0; i < tmp.size() - 1; i++) {
      adj[tmp[i]].push_back(tmp[i + 1]);
      deg[tmp[i + 1]]++;
    }
  }

  cout << phase();
}