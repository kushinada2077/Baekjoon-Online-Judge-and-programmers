#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

int upper_bound(vector<int>& a, int x) {
  int lo = -1, hi = a.size();
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] >= x) hi = mid;
    else lo = mid;
  }
  return hi;
}
int main() {
  fastio;
  unordered_set<int> dup;
  int n;
  cin >> n;
  vector<int> a;
  vector<int> cpy(n);
  for (int i = 0; i < n; ++i) {
    cin >> cpy[i];
    if (dup.find(cpy[i]) != dup.end()) continue;
    dup.insert(cpy[i]);
    a.push_back(cpy[i]);
  }
  sort(a.begin(), a.end());
  for (auto v : cpy) cout << upper_bound(a, v) << " ";
}