#define ll long long
#define PAIR pair<int, int>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int n, v;
vector<pair<int, int>> d(1005);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ans = -1;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> v;
    d[i] = {v, v};
    for (int j = 0; j < i; ++j) {
      auto [sum, x] = d[j];
      if (v > x && sum + v > d[i].first) {
        d[i] = {sum + v, v};
      }
    }
    ans = max(ans, d[i].first);
  }
  cout << ans;
}