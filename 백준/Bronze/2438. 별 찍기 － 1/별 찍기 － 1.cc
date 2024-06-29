#define ll long long
#include <iostream>
#include <vector>
using namespace std;

void sol(int n) {
  if (n == 0) return;
  sol(n - 1);
  for (int i = 0; i < n; ++i) cout << "*";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  sol(n);
}