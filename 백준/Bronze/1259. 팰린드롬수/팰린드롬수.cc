#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    string str;
    cin >> str;
    if (str == "0") break;
    bool flag = true;

    for (int i = 0; i < str.size() / 2 + 1; i++) {
      int j = str.size() - i - 1;
      if (str[i] != str[j]) {
        flag = false;
        break;
      }
    }

    if (flag)
      cout << "yes\n";
    else
      cout << "no\n";
  }
}