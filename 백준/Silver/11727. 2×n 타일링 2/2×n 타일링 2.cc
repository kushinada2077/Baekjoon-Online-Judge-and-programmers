#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

const int M = 10007;
vector<ll> d(1005, -1);

ll f(int n) {
  if (n == 1) return 1;
  if (n == 2) return 3;
  if (d[n] != -1) return d[n];

  ll result = (f(n - 1) + 2 * f(n - 2)) % M;
  d[n] = result;
  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cout << f(n);
}