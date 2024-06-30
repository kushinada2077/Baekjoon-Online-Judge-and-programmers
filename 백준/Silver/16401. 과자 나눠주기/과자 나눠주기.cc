#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

bool isPossible(vector<ll>& a, int len, int target) {
  ll sum = 0;
  for (auto l : a) sum += l / len;
  return sum >= target;
}
ll sol(vector<ll>& a, int target) {
  ll lo = 0, hi = 1e9 + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (isPossible(a, mid, target)) lo = mid;
    else hi = mid;
  }
  return lo;
}
int main() {
  fastio;
  int m, n;
  cin >> m >> n;
  vector<ll> snack(n);
  for (int i = 0; i < n; ++i) cin >> snack[i];
  cout << sol(snack, m);
}