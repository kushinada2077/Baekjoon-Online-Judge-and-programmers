#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int main() {
  fastio;
  int n, x, cnt = 1;
  cin >> n;
  stack<int> s;
  for (int i = 0; i < n; ++i) {
    while (!s.empty() && cnt == s.top()) {
      s.pop();
      cnt++;
    }
    cin >> x;
    if (x != cnt) {
      if (!s.empty() && s.top() < x) {
        cout << "Sad\n";
        return 0;
      }
      s.push(x);
    } else {
      cnt++;
    }
  }
  cout << "Nice\n";
}