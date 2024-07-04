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

// d[i] = i - 1번째 날까지 상담했을때의 최대 수익
int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> t(n + 1), p(n + 1), d(n + 2);
  for_in(n) {
    cin >> t[i + 1];
    cin >> p[i + 1];
  }
  for_in(i, 1, n + 1) {
    d[i] = max(d[i], d[i - 1]);
    int nxt = i + t[i];
    if (nxt - 1 <= n) d[nxt] = max(d[nxt], d[i] + p[i]);
  }
  cout << max(d[n], d[n + 1]);
}