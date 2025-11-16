#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::string s;
  std::cin >> n >> s;
  std::stack<int> stack;

  int ans = 0;
  stack.push(-1);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      stack.push(i);
    } else if (s[i] == ')') {
      stack.pop();
      if (stack.empty()) {
        stack.push(i);
      } else {
        ans = std::max(ans, i - stack.top());
      }
    }
  }

  std::cout << ans << "\n";
}