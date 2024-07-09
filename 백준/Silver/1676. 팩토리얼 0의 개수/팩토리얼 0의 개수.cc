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
  int cnt = 0;

  int t = 5;
  int r = 0;
  while (t <= n) {
    r += n / t;
    t *= 5;
  }
  cout << r << "\n";
}