#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

int fac(int n) {
  if (n == 0) return 1;
  return n * fac(n - 1);
}
int main() {
  fastio;
  int n, m;
  cin >> n >> m;
  int nf = fac(n - m), cnt = 0;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  sort(all(a));
  do {
    cnt++;
    if (cnt != nf) continue;
    for (int i = 0; i < m; ++i) cout << a[i] << " ";
    cout << "\n";
    cnt = 0;
  } while (next_permutation(all(a)));
}