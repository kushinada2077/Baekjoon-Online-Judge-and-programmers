#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <tuple>
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
  int n, op;
  deque<char> dq;
  stack<int> s;
  char c;
  cin >> n;
  while (n--) {
    cin >> op;
    if (op == 1) {
      cin >> c;
      dq.push_back(c);
      s.push(2);
    } else if (op == 2) {
      cin >> c;
      dq.push_front(c);
      s.push(1);
    } else if (op == 3) {
      if (s.empty()) continue;
      int state = s.top();
      s.pop();
      if (state == 1) dq.pop_front();
      else if (state == 2) dq.pop_back();
    }
  }
  if (s.empty()) cout << "0\n";
  else
    for (auto& c : dq) cout << c;
}