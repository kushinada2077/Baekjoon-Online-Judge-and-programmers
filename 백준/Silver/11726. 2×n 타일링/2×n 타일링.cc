#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

const int M = 10007;
ll d[1005][2];

ll f(int n, int k) {
  if (n == 1) return k == 0 ? 0 : 1;
  if (n == 2) return 1;
  if (d[n][k] != -1) return d[n][k];

  ll result = 0;
  if (k == 0) result = result + ((f(n - 2, 0) + f(n - 2, 1)) % M);
  if (k == 1) result = (result + ((f(n - 1, 0) + f(n - 1, 1)) % M)) % M;
  d[n][k] = result;
  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 1005; ++i) fill(d[i], d[i] + 2, -1);
  int n;
  cin >> n;
  cout << (f(n, 0) + f(n, 1)) % M;
}