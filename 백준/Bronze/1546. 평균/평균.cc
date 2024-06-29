#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, mx = -1, sum = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
  }
  double ans = (double)sum / mx * 100 / n;
  cout << ans;
}