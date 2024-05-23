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

  while (true) {
    string a;
    stack<char> s;
    getline(cin, a);
    if (a == ".") break;
    bool flag = true;
    for (auto c : a) {
      if (c == '(' || c == '[') {
        s.push(c);
      } else if (c == ')') {
        if (s.empty() || s.top() != '(') {
          flag = false;
          break;
        }
        s.pop();
      } else if (c == ']') {
        if (s.empty() || s.top() != '[') {
          flag = false;
          break;
        }
        s.pop();
      }
    }
    if (!s.empty()) flag = false;

    if (flag) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
}