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
  int n;
  cin >> n;
  vector<int> a(n), ans;
  stack<pair<int, int>> s;
  for (auto& i : a) cin >> i;
  for (int i = n; i != 0; --i) {
    while (!s.empty() && s.top().X == a[i - 1]) s.pop();
    if (s.empty()) ans.pb(-1);
    else ans.pb(s.top().Y);
    s.push({a[i - 1], i});
  }
  for (auto i = ans.rbegin(); i != ans.rend(); ++i) cout << *i << " ";
}