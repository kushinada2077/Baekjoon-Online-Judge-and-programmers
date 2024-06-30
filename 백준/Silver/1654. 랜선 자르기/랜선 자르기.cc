#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int get_num(vector<int>& cable, int len) {
  int ret = 0;
  for (auto c : cable) ret += c / len;
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> k >> n;
  ll lo = 1, hi = (1l << 31);
  vector<int> cable(k);
  for (int i = 0; i < k; ++i) cin >> cable[i];
  while (lo + 1 < hi) {
    ll mid = (lo + hi) / 2;
    ll num = get_num(cable, mid);
    if (num >= n)
      lo = mid;
    else
      hi = mid;
  }
  cout << lo;
}