#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

ll d[91][2];
int N;

ll f(int n, int k) {
  if (n == 1) return 1;
  if (d[n][k] != -1) return d[n][k];

  ll result = f(n - 1, 0);
  if (k == 0) result += f(n - 1, 1);
  d[n][k] = result;
  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < 91; ++i) fill(d[i], d[i] + 2, -1);
  cout << f(N, 1);
}