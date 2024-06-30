#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

unordered_map<int, int> d;
int upper_bound(vector<int>& a, int x) {
  int lo = -1, hi = a.size();
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] >= x) hi = mid;
    else lo = mid;
  }
  return hi;
}
int compress(vector<int>& a, int x) {
  if (d.find(x) != d.end()) return d[x];
  d[x] = upper_bound(a, x);
  return d[x];
}
int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> erase_dup;
  vector<int> tmp(n);
  for (int i = 0; i < n; ++i) {
    cin >> tmp[i];
    a[i] = tmp[i];
  }
  sort(tmp.begin(), tmp.end());
  for (int i = 0; i < n; ++i) {
    if (i > 0 && tmp[i] == tmp[i - 1]) continue;
    erase_dup.push_back(tmp[i]);
  }
  for (auto v : a) cout << compress(erase_dup, v) << " ";
}
