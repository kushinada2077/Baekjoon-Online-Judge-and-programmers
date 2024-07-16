#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

int f(int n) {
  int ret = 1;
  for (int i = 0; i < 4; ++i) ret *= (n - i);
  for (int i = 4; i != 1; --i) ret /= i;
  return ret;
}
int main() {
  fastio;
  int n;
  cin >> n;
  cout << f(n);
}