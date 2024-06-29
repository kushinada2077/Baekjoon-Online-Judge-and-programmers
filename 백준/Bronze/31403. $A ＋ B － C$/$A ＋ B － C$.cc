#define ll long long
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int sol(int a, int b) {
  int cnt = 0;
  int tmp = b;
  while (tmp) {
    a *= 10;
    tmp /= 10;
  }
  return a + b;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  cout << a + b - c << "\n";
  cout << sol(a, b) - c;
}