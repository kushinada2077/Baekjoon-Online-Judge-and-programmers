#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

int conv(vector<int>& a, int d) {
  int ret = 0;
  int m = 1;
  for (int i = si(a) - 1; i >= 0; --i) {
    ret += m * a[i];
    m *= d;
  }
  return ret;
}
int main() {
  fastio;
  int N, d;
  cin >> N >> d;
  vector<int> num;
  for (int i = 0; i < d; ++i) num.pb(i);
  do {
    if (num[0] == 0) continue;
    int a = conv(num, d);
    if (a > N) {
      cout << a << "\n";
      return 0;
    }
  } while (next_permutation(all(num)));
  cout << "-1\n";
}