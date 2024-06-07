#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int N;
int d[12];
// f(n) = n을 1,2,3의 합으로 나타낼 수 있는 경우의 수
int f(int n) {
  if (n == 1) return 1;
  if (n == 2) return 2;
  if (n == 3) return 4;
  if (d[n]) return d[n];

  int result = f(n - 3) + f(n - 2) + f(n - 1);
  d[n] = result;
  return result;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> N;
    cout << f(N) << "\n";
  }
}