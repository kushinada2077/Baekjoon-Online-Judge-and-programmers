#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int N, M, n;
ll d[100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  ll sum = 0;
  for (int i = 1; i < N + 1; ++i) {
    cin >> n;
    sum += n;
    d[i] = sum;
  }
  while (M--) {
    cin >> N >> n;
    cout << d[n] - d[N - 1] << "\n";
  }
}