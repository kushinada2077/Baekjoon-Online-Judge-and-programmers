#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int N, M, cnt, a, b, c, p[100001];
vector<int> ans;
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
  cin >> N >> M;
  while (M--) {
    cin >> a >> b >> c;
    edge.push_back({c, a, b});
  }

  fill(p, p + 1 + N, -1);
  sort(edge.begin(), edge.end());
  for (auto [cost, a, b] : edge) {
    if (!is_diff_group(a, b)) continue;
    ans.push_back(cost);
    if (++cnt >= N - 1) break;
  }

  ans.pop_back();
  cnt = 0;
  for (auto n : ans) cnt += n;

  cout << cnt;
}