#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  fastio;
  int a, b;
  cin >> a >> b;
  int g = gcd(a, b);
  cout << g << "\n" << a * b / g << "\n";
}