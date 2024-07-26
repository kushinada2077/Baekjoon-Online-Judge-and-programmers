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
  int n, L;
  deque<int> q;
  cin >> n >> L;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  int l = 0;
  for (int r = 0; r < n; ++r) {
    while (!q.empty() && q.back() > a[r]) q.pop_back();
    q.push_back(a[r]);
    if (r - l + 1 > L) {
      if (q.front() == a[l]) q.pop_front();
      l++;
    }
    cout << q.front() << " ";
  }
}