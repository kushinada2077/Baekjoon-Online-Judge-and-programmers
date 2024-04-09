#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int N, x, cnt, p[1001];
long long ans;
vector<TUPLE> edge;

int find(int v) {
  if (p[v] < 0) return v;
  return p[v] = find(p[v]);
}

bool is_diff_group(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return 0;
  if (p[a] == p[b]) p[a]--;
  if (p[a] < p[b])
    p[b] = a;
  else
    p[a] = b;

  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  fill(p, p + 1 + N, -1);

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> x;
      if (x == 0) continue;
      edge.push_back({x, i, j});
    }
  }

  sort(edge.begin(), edge.end());

  for (auto [cost, a, b] : edge) {
    if (!is_diff_group(a, b)) continue;
    ans += cost;
    if (++cnt >= N - 1) break;
  }

  cout << ans;
}