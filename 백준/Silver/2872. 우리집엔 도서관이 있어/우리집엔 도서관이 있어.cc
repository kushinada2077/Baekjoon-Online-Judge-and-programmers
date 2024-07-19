#include <algorithm>
#include <iostream>
#include <stack>
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
  int n, ans = 0;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  int cur = n;
  for (int i = n - 1; i >= 0; --i)
    if (a[i] == cur) cur--;
  cout << cur << "\n";
}