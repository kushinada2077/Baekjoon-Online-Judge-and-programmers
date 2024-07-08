#include <algorithm>
#include <iostream>
#include <queue>
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

#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;

ll factorial(ll n) {
  if (n == 0) return 1;
  ll ret = n * factorial(n - 1);
  return ret;
}
vector<int> f1(int n, ll k) {
  k--;
  vector<int> nums;
  vector<int> ret;
  for_in(n) nums.pb(i + 1);
  ll nf = factorial(n);
  while (n > 0) {
    nf /= n--;
    ret.pb(nums[k / nf]);
    nums.erase(nums.begin() + (k / nf));
    k %= nf;
  }
  return ret;
}
ll f2(vector<int>& se, int n) {
  vector<int> nums;
  for_in(n) nums.pb(i + 1);
  ll ret = 0, nf = factorial(n);
  for (auto v : se) {
    int idx = find(all(nums), v) - nums.begin();
    nums.erase(nums.begin() + idx);
    nf /= n--;
    ret += idx * nf;
  }
  return ret + 1;
}
int main() {
  fastio;
  int n, c;
  ll k;
  cin >> n >> c;
  if (c == 1) {
    cin >> k;
    vector<int> ans = f1(n, k);
    for (auto n : ans) cout << n << " ";
  } else {
    vector<int> se(n);
    for_in(n) cin >> se[i];
    cout << f2(se, n);
  }
}