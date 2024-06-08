#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int N;
int d[1000005];
int path[1000005];

int f(int n) {
  if (n == 1) return 0;
  if (d[n]) return d[n];

  int result = f(n - 1) + 1;
  path[n] = n - 1;
  if (n % 2 == 0 && result > f(n / 2) + 1) {
    result = f(n / 2) + 1;
    path[n] = n / 2;
  }
  if (n % 3 == 0 && result > f(n / 3) + 1) {
    result = f(n / 3) + 1;
    path[n] = n / 3;
  }
  d[n] = result;
  return result;
}
void track(int k) {
  while (k != -1) {
    cout << k << " ";
    k = path[k];
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  path[1] = -1;
  cin >> N;
  cout << f(N) << "\n";
  track(N);
}