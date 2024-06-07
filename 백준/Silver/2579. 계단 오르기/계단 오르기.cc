#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

const int IM = 500000;
int N, stair[305];
int d[305];
// f(n) = n번째 계단까지의 밟지 않을 합의 최소, n번째는 밟지 않음
int f(int n) {
  if (n == 1) return stair[1];
  if (n == 2) return stair[2];
  if (d[n] != IM) return d[n];

  int result = stair[n] + f(n - 2);           // n-2를 밟지 않음
  result = min(result, stair[n] + f(n - 3));  // n-2를 밟음
  d[n] = result;
  return result;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  fill(d, d + N + 1, IM);
  int sum = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> stair[i];
    sum += stair[i];
  }
  sum = sum - min(f(N - 1), f(N - 2));
  cout << sum;
}