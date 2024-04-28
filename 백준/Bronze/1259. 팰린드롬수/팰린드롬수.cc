#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isPal(int n) {
  int p = 0;
  int m = n;

  while (m) {
    p = p * 10 + m % 10;
    m /= 10;
  }

  return p == n;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    cout << (isPal(n) ? "yes\n" : "no\n");
  }
}
