#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int n, N, M = 1e9;
int d[105][10];

// 처음 숫자가 k면서 길이가 n인 계단수의 개수
ll f(int n, int k) {
  if (n == 1) return 1;
  if (d[n][k]) return d[n][k];

  ll result;
  if (k == 9)
    result = f(n - 1, k - 1) % M;
  else if (k == 0)
    result = f(n - 1, k + 1) % M;
  else
    result = (f(n - 1, k + 1) + f(n - 1, k - 1)) % M;
  d[n][k] = result;
  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  int sum = 0;
  for (int i = 1; i < 10; ++i) sum = (sum + f(N, i)) % M;
  cout << sum;
}