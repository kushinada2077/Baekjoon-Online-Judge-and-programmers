#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

int main() {
  fastio;
  int n, m, k;
  cin >> n >> m >> k;
  int mk = m * k;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  sort(all(a), greater<>());
  int sum = 0;
  for (int i = 0; i < si(a); ++i) {
    sum += a[i];
    if (sum >= mk) {
      cout << i + 1 << "\n";
      return 0;
    }
  }
  cout << "STRESS\n";
}