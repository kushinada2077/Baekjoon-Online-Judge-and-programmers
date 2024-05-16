#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  stack<int> s;
  int k, x;
  cin >> k;

  while (k--) {
    cin >> x;
    if (x)
      s.push(x);
    else
      s.pop();
  }

  k = 0;
  while (!s.empty()) {
    k += s.top();
    s.pop();
  }
  cout << k;
}