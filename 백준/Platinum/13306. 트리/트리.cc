#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(i, x) for (int i = 0; i < x; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
using namespace std;

int p[200005], d[200005];
int find(int a) {
  if (p[a] < 0) return a;
  p[a] = find(p[a]);
  return p[a];
}
void merge(int a, int b) {
  int pa = find(a), pb = find(b);
  if (pa == pb) return;
  if (-pa >= -pb) {
    p[pa] += p[pb];
    p[pb] = pa;
  } else {
    p[pb] += p[pa];
    p[pa] = pb;
  }
}
int main() {
  fastio;
  int n, q, x, a, b;
  cin >> n >> q;
  fill(p, p + n + 1, -1);
  for_in(i, n - 1) cin >> d[i + 2];
  stack<vector<int>> s;
  vector<string> ans;
  for_in(i, n + q - 1) {
    cin >> x;
    if (x == 0) {
      cin >> b;
      s.push({x, b});
    } else {
      cin >> a >> b;
      s.push({x, a, b});
    }
  }
  while (!s.empty()) {
    auto op = s.top();
    s.pop();
    if (op[0] == 0) merge(d[op[1]], op[1]);
    else {
      int pa = find(op[1]), pb = find(op[2]);
      if (pa == pb) ans.push_back("YES");
      else ans.push_back("NO");
    }
  }

  for (auto i = ans.rbegin(); i < ans.rend(); ++i) cout << *i << "\n";
}