#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

int main() {
  fastio;
  int n, l;
  deque<int> q;
  cin >> n >> l;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  for (int i = 0; i < n; ++i) {
    while (!q.empty() && q.back() > a[i]) q.pop_back();
    q.push_back(a[i]);
    cout << q.front() << " ";
    if (i >= l - 1 && q.front() == a[i - l + 1]) q.pop_front();
  }
}