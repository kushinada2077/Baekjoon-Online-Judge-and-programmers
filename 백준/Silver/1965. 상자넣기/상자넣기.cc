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

int n, d[1005];
int main() {
  fastio;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  for (int i = 0; i < n; ++i) {
    d[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (a[j] < a[i] && d[i] < d[j] + 1) d[i] = d[j] + 1;
    }
  }
  cout << *max_element(d, d + n) << "\n";
}