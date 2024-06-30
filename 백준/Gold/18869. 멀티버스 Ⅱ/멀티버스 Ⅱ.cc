#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

int lb(vector<int>& a, int x) {
  int lo = -1, hi = a.size();
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] >= x) hi = mid;
    else lo = mid;
  }
  return hi;
}
void compress(vector<int>& a) {
  vector<int> cpy = a;
  sort(cpy.begin(), cpy.end());
  cpy.erase(unique(cpy.begin(), cpy.end()), cpy.end());
  for (int i = 0; i < a.size(); ++i) {
    a[i] = lb(cpy, a[i]);
  }
}
bool comp(vector<int>& a, vector<int>& b) {
  int n = a.size();
  for (int i = 0; i < n; ++i)
    if (a[i] != b[i]) return false;
  return true;
}
int main() {
  fastio;
  int m, n, ans = 0;
  cin >> m >> n;
  vector<vector<int>> space;
  for (int i = 0; i < m; ++i) {
    vector<int> s(n);
    for (int j = 0; j < n; ++j) cin >> s[j];
    compress(s);
    space.push_back(s);
  }

  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      ans += comp(space[i], space[j]);
    }
  }
  cout << ans;
}