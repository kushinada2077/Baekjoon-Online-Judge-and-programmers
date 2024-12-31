#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, A[1000005], gcdl[1000005], gcdr[1000005];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i];
  for (int i = 0; i < n; ++i) {
    gcdl[i + 1] = gcd(A[i], gcdl[i]);
    gcdr[n - i - 1] = gcd(A[n - i - 1], gcdr[n - i]);
  }

  int maxGcd = 0, idx = -1;
  for (int i = 0; i < n; ++i) {
    int newGcd = gcd(gcdl[i], gcdr[i + 1]);
    if (maxGcd < newGcd && A[i] % newGcd) {
      maxGcd = newGcd;
      idx = i;
    }
  }

  if (maxGcd == 0) cout << "-1\n" << "\n";
  else cout << maxGcd << " " << A[idx] << "\n";
}