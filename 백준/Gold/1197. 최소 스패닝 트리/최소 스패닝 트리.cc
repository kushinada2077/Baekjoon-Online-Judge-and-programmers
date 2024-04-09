#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int V, E, A, B, C, ans, p[10001];
vector<tuple<int, int, int>> edge;

int find(int n) {
  if (p[n] < 0) return n;
  p[n] = find(p[n]);
  return p[n];
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  p[a] = b;
}

bool is_diff_group(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> V >> E;
  fill(p, p + 1 + V, -1);
  while (E--) {
    cin >> A >> B >> C;
    edge.push_back({C, A, B});
  }

  sort(edge.begin(), edge.end());

  for (auto [cost, a, b] : edge) {
    if (!is_diff_group(a, b)) continue;
    ans += cost;
    merge(a, b);
  }

  cout << ans;
}