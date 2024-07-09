#include <algorithm>
#include <iostream>
#include <set>
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
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

int cnt[2505];
int main() {
  fastio;
  int T, n, x;
  cin >> T;
  for_in(t, T) {
    cin >> n;
    for_in(2 * n * n - n) {
      cin >> x;
      cnt[x]++;
    }
    cout << "Case #" << t + 1 << ": ";
    for_in(2500) if (cnt[i] & 1) {
      cout << i << " ";
      cnt[i] = 0;
    }
    cout << "\n";
  }
}