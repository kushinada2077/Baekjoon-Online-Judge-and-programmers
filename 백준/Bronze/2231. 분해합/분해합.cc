#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

int f(int n) {
  int ret = n;
  while (n > 0) {
    ret += n % 10;
    n /= 10;
  }
  return ret;
}
int main() {
  fastio;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    if (f(i) == n) {
      cout << i << "\n";
      return 0;
    }
  }
  cout << "0\n";
}