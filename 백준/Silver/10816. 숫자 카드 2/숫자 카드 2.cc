#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

int cnt[20000010];
int main() {
  fastio;
  const int OFF = 10000000;
  int n, m, x;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    cnt[x + OFF]++;
  }
  cin >> m;
  while (m--) {
    cin >> x;
    cout << cnt[x + OFF] << " ";
  }
}