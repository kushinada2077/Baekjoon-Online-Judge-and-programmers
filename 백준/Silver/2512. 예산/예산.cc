#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR_IN_1(n) for (int i = 0; i < n; ++i)
#define FOR_IN_2(i, n) for (int i = 0; i < n; ++i)
#define FOR_IN_3(i, m, n) for (int i = m; i < n; ++i)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define for_in(...) GET_MACRO(__VA_ARGS__, FOR_IN_3, FOR_IN_2, FOR_IN_1)(__VA_ARGS__)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;

bool f(vector<int>& a, int tot, int bud) {
  int sum = 0;
  for (auto n : a) sum += min(n, bud);
  return tot >= sum;
}
int sol(vector<int>& a, int tot) {
  int lo = 1, hi = 1e9 + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (f(a, tot, mid)) lo = mid;
    else hi = mid;
  }
  return lo;
}
int main() {
  fastio;
  int n, sum = 0;
  cin >> n;
  vector<int> a(n);
  for_in(n) {
    cin >> a[i];
    sum += a[i];
  }
  int tot;
  cin >> tot;
  if (tot >= sum) {
    cout << *max_element(all(a));
    return 0;
  }
  cout << sol(a, tot);
}