#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

int up(vector<int>& a, int x) {
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
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> uni(n);
  for (int i = 0; i < n; ++i) {
    cin >> uni[i];
    a[i] = uni[i];
  }
  sort(uni.begin(), uni.end());
  uni.erase(unique(uni.begin(), uni.end()), uni.end());
  for (auto v : a) cout << up(uni, v) << " ";
}