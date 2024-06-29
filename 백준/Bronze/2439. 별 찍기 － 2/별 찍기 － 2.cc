#define ll long long
#include <iostream>
#include <vector>
using namespace std;

int n;
void sol(int k) {
  if (k == 0) return;
  sol(k - 1);
  for (int i = 0; i < n - k; ++i) cout << " ";
  for (int i = 0; i < k; ++i) cout << "*";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  sol(n);
}