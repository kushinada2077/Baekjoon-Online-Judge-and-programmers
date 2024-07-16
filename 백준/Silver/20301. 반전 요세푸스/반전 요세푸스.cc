#include <algorithm>
#include <deque>
#include <iostream>
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
  int n, k, m;
  cin >> n >> k >> m;
  deque<int> dq;
  for (int i = 1; i <= n; ++i) dq.push_back(i);
  int cnt = 0;
  bool s = false;
  while (!dq.empty()) {
    if (!s) {
      for_in(k - 1) {
        dq.push_back(dq.front());
        dq.pop_front();
      }
      cout << dq.front() << "\n";
      dq.pop_front();
      cnt++;
    } else {
      for_in(k - 1) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
      cout << dq.back() << "\n";
      dq.pop_back();
      cnt++;
    }
    if (cnt == m) {
      /*  if (!s) {
          dq.push_front(dq.back());
          dq.pop_back();
        } else {
          dq.push_back(dq.front());
          dq.pop_front();
        }
        */
      s = !s;
      cnt = 0;
    }
  }
}