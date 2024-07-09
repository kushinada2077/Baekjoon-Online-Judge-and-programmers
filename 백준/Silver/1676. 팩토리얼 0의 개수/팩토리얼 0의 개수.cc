#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  int cnt2 = 0, cnt5 = 0;
  for (int i = 2; i <= n; i += 2) {
    int tmp = i;
    while (tmp % 2 == 0) {
      cnt2++;
      tmp /= 2;
    }
  }
  for (int i = 5; i <= n; i += 5) {
    int tmp = i;
    while (tmp % 5 == 0) {
      cnt5++;
      tmp /= 5;
    }
  }
  cout << min(cnt2, cnt5);
}