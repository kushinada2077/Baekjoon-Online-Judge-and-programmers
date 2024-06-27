#define ll long long
#define PAIR pair<int, int>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
using namespace std;

int n, t[16], p[16], d[16];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> t[i] >> p[i];

  for (int i = n - 1; i >= 0; --i) {
    int nxt = i + t[i];
    if (nxt <= n)
      d[i] = max(d[nxt] + p[i], d[i + 1]);
    else
      d[i] = d[i + 1];
  }
  cout << *max_element(d, d + n);
}