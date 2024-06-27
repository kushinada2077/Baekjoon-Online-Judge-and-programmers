#define ll long long
#define PAIR pair<int, int>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int n, v, a[1005], d[1005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    d[i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[i] > a[j]) d[i] = max(d[j] + 1, d[i]);
    }
  }
  cout << *max_element(d, d + n);
}