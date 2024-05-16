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

  int n, x, cur = 1;
  stack<int> s;
  vector<char> ans;
  cin >> n;

  while (n--) {
    cin >> x;

    while (cur <= x) {
      ans.push_back('+');
      s.push(cur);
      cur++;
    }

    if (s.top() == x) {
      ans.push_back('-');
      s.pop();
    } else {
      cout << "NO";
      exit(0);
    }
  }

  for (auto c : ans) cout << c << "\n";
}