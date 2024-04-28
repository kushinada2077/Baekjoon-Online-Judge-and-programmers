#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  int T;
  cin >> T;

  while (T--) {
    int sum = 0, cnt = 0;
    cin >> s;
    for (auto c : s) {
      if (c == 'O') {
        cnt++;
      } else if (c == 'X') {
        cnt = 0;
      }
      sum += cnt;
    }
    cout << sum << "\n";
  }
}